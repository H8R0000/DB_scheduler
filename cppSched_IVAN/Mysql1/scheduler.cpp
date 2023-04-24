#include <iostream>
#include <atltime.h>
#include <mysqlx/xdevapi.h>
#include "entities.h"
#include "functions_for_specs.h"
#include "math.h"
#include <algorithm>

std::vector<std::string> getScheduler(mysqlx::Session& sess, CTime& startDate, std::vector<Spec>& specs, std::vector <Student>& students, \
	std::vector <Teacher>& teachers, std::vector <Laba>& labs) {

	// TODO: change to MAX_STUDENTS_IN_GROUP = 10
	const int MAX_STUDENTS_IN_GROUP = 4;
	const int MAX_SHIFTS_PER_DAY = 2;

	// get amount of students, teachers, labs
	int studentsCount = students.size();

	int teachersCount = teachers.size();
	assert(teachersCount != 0);

	int totalTeachersCountForAllSpecs = std::ceil((float)studentsCount / (MAX_STUDENTS_IN_GROUP * MAX_SHIFTS_PER_DAY));
	assert(totalTeachersCountForAllSpecs <= teachersCount);

	int maxLabGroups = teachersCount * 2;

	int labsCount = labs.size();

	//////////////////////////////////////////////// get Scheduler /////////////////////////////////////////////////////
	std::vector<Group> groups;
	int teacherIndex = 0;

	for (Spec spec : specs) {
		cout << spec.name << endl;
		std::vector<Student> specStudents = fetchAllStudentsWithSpec(sess, spec.name);

		const int specStudentsCount = specStudents.size();
		assert(specStudentsCount != 0);

		int teachersCountForSpec = std::ceil((float)specStudentsCount / (MAX_STUDENTS_IN_GROUP * MAX_SHIFTS_PER_DAY));
		// cout << "specStudentsCount = " << specStudentsCount << endl;
		int aproxStudentsCountPerTeacher = std::floor((float)specStudentsCount / teachersCountForSpec);
		// cout << "teachersCountForSpec = " << teachersCountForSpec << endl;	

		std::vector<string> specLabas = fetchAllLabsForSpec(sess, spec.name);

		int groupIndex = 0;
		int studentIndex = 0;

		std::vector<Group> groupsForSpec;

		// split students by groups
		for (Student st : specStudents) {
			StudentLabs studentLabs;
			studentLabs.student = st;

			std::vector<string> groupLabs(specLabas);
			std::rotate(groupLabs.begin(), groupLabs.begin() + studentIndex, groupLabs.end());

			studentLabs.labs = groupLabs;

			if (groupsForSpec.size() < teachersCountForSpec) {
				Group group;
				group.spec = spec;

				group.teacher = teachers.at(teacherIndex);
				teacherIndex++;

				if (teacherIndex >= teachersCount) {
					teacherIndex = 0;
				}
				
				group.studentLabs.push_back(studentLabs);

				groupsForSpec.push_back(group);
			}
			else {
				groupsForSpec.at(groupIndex).spec = spec;
				groupsForSpec.at(groupIndex).studentLabs.push_back(studentLabs);
			}

			groupIndex++;

			if (groupIndex >= teachersCountForSpec) {
				groupIndex = 0;
			}

			studentIndex++;
		}

		for (Group group : groupsForSpec) {
			std::cout << "groupTeacher " << group.teacher.surname << endl;

			cout << "students: " << endl;
			for (auto stLabs : group.studentLabs) {
				cout << stLabs.student.surname << " : ";

				for (auto lab : stLabs.labs) {
					cout << lab << ", ";
				}
				cout << endl;
			}
			cout << endl;
		}

		groups += groupsForSpec;
	}

	int dayCount = 0;

	std::map<std::string, SchedulerEntry> schedule;

	for (auto group : groups) {
		CTime firstShiftDateTime = startDate + CTimeSpan(dayCount, 0, 0, 0);

		Teacher teacher = group.teacher;
		std::string teacherFullName = teacher.surname + " " + teacher.name + " " + teacher.patronymic;

		std::vector<StudentLabs> firstShiftStudentLabs;
		std::vector<StudentLabs> secondShiftStudentLabs;

		firstShiftStudentLabs.assign(group.studentLabs.begin(), group.studentLabs.begin() + MAX_STUDENTS_IN_GROUP);
		secondShiftStudentLabs.assign(group.studentLabs.begin() + MAX_STUDENTS_IN_GROUP, group.studentLabs.end());

		SchedulerEntry schedulerEntry;
		schedulerEntry.date = firstShiftDateTime;
		schedulerEntry.firstShiftStudentLabs = firstShiftStudentLabs;
		schedulerEntry.secondShiftStudentLabs = secondShiftStudentLabs;

		schedule.insert(std::pair{ teacherFullName, schedulerEntry });

		dayCount++;
	}

	std::vector <std::string> outScheduler;

	return outScheduler;
}