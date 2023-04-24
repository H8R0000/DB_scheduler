#include <iostream>
#include <atltime.h>
#include <mysqlx/xdevapi.h>
#include <algorithm>
#include <cmath>
#include <nlohmann/json.hpp>

#include "entities.h"
#include "functions_for_specs.h"

using json = nlohmann::json;

std::vector<Schedule::TeacherEntry> getScheduler(mysqlx::Session& sess, CTime& startDate, std::vector<Spec>& specs, std::vector <Student>& students, \
	std::vector <Teacher>& teachers, std::vector <Laba>& labs) {

	int dayOfWeek = startDate.GetDayOfWeek();
	assert(dayOfWeek != 1); // date is not Sunday
	assert(dayOfWeek != 7); // date is not Saturday

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
		// cout << spec.name << endl;
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

		/*for (Group group : groupsForSpec) {
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
		}*/

		groups += groupsForSpec;
	}

	std::vector<Schedule::TeacherEntry> schedule;

	for (auto group : groups) {
		std::vector<StudentLabs> firstShiftStudentLabs;
		std::vector<StudentLabs> secondShiftStudentLabs;

		firstShiftStudentLabs.assign(group.studentLabs.begin(), group.studentLabs.begin() + MAX_STUDENTS_IN_GROUP);
		secondShiftStudentLabs.assign(group.studentLabs.begin() + MAX_STUDENTS_IN_GROUP, group.studentLabs.end());

		int studentLabsCount = group.studentLabs.at(0).labs.size();

		std::vector<Schedule::DateEntry> dateEntries;

		for (int i = 0; i < studentLabsCount; i++) {
			CTime actualDateTime = startDate + CTimeSpan(i * 7, 0, 0, 0);

			std::vector<Schedule::ShiftEntry> firstShift;

			for (auto firstShiftStLaba : firstShiftStudentLabs) {
				Schedule::ShiftEntry entry;
				entry.student = firstShiftStLaba.student.surname + " " + firstShiftStLaba.student.name 
					+ " " + firstShiftStLaba.student.patronymic;
				entry.laba = firstShiftStLaba.labs.at(i);

				firstShift.push_back(entry);
			}

			std::vector<Schedule::ShiftEntry> secondShift;

			for (auto secondShiftStLaba : secondShiftStudentLabs) {
				Schedule::ShiftEntry entry;
				entry.student = secondShiftStLaba.student.surname + " " + secondShiftStLaba.student.name
					+ " " + secondShiftStLaba.student.patronymic;
				entry.laba = secondShiftStLaba.labs.at(i);

				secondShift.push_back(entry);
			}

			Schedule::DateEntry schedulerEntry;

			// Convert a TCHAR string to a LPCSTR
			CT2CA pszConvertedAnsiString(actualDateTime.Format(_T("%F")).GetString()); // format as YYYY-MM-DD
			// construct a std::string using the LPCSTR input
			std::string strStd(pszConvertedAnsiString);
			schedulerEntry.date = strStd; 

			schedulerEntry.firstShift = firstShift;
			schedulerEntry.secondShift = secondShift;

			dateEntries.push_back(schedulerEntry);
		}

		Teacher teacher = group.teacher;
		Schedule::TeacherEntry teacherEntry;
		teacherEntry.teacher = teacher.surname + " " + teacher.name + " " + teacher.patronymic;
		teacherEntry.schedule = dateEntries;

		schedule.push_back(teacherEntry);
	}

	return schedule;
}