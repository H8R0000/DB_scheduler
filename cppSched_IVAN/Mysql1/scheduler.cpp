#include <iostream>
#include <mysqlx/xdevapi.h>
#include "entities.h"
#include "functions_for_specs.h"
#include "math.h"
#include <algorithm>

std::vector<std::string> getScheduler(mysqlx::Session& sess, std::vector<Spec>& specs, std::vector <Student>& students, \
	std::vector <Teacher>& teachers, std::vector <Laba>& labs) {

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

		std::vector<Group> groupsForSpec;

		// split students by groups
		for (Student st : specStudents) {
			if (groupsForSpec.size() < teachersCountForSpec) {
				Group group;
				group.spec = spec;

				group.teacher = teachers.at(teacherIndex);
				teacherIndex++;

				if (teacherIndex >= teachersCount) {
					teacherIndex = 0;
				}

				group.students.push_back(st);

				std::vector<string> groupLabs(specLabas);
				std::rotate(groupLabs.begin(), groupLabs.begin() + groupIndex, groupLabs.end());
				group.labas = groupLabs;

				groupsForSpec.push_back(group);
			}
			else {
				groupsForSpec.at(groupIndex).spec = spec;
				groupsForSpec.at(groupIndex).students.push_back(st);
			}

			groupIndex++;

			if (groupIndex >= teachersCountForSpec) {
				groupIndex = 0;
			}
		}

		for (Group group : groupsForSpec) {
			std::cout << "groupTeacher " << group.teacher.surname << endl;

			cout << "students: " << endl;
			for (Student st : group.students) {
				cout << st.surname << ", ";
			}
			cout << endl;

			cout << "labs: " << endl;
			for (auto lab : group.labas) {
				cout << lab << ", ";
			}
			cout << endl;
		}

		groups += groupsForSpec;
	}

	std::vector <std::string> outScheduler;

	return outScheduler;
}