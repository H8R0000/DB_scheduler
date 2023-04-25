#include <iostream>
#include <mysqlx/xdevapi.h>
#include <atltime.h>
#include <cxxopts.hpp>
#include <regex>
#include <sstream>

#include "entities.h"
#include "students.h"
#include "teachers.h"
#include "labs.h"
#include "specs.h"
#include "scheduler.h"

using ::std::cout;
using ::std::endl;

int main(int argc, char** argv)
{
	try
	{
		cxxopts::Options options("scheduler", "Creating a schedule");

		options.add_options()
			("d,date", "Start date (YYYY-MM-DD)", cxxopts::value<std::string>());

		auto result = options.parse(argc, argv);

		std::string sDate;

		if (result.count("date")) {
			sDate = result["date"].as<std::string>();
		}
		else {
			cout << options.help() << endl;
			exit(0);
		}

		if (!std::regex_match(sDate, std::regex("\\d{4}-\\d{2}-\\d{2}"))) {
			cout << "ERROR: invalid date " << sDate << endl;
			exit(1);
		}

		std::vector<std::string> dateParts;
		std::stringstream sStream(sDate);
		std::string segment;

		while (std::getline(sStream, segment, '-')) {
			dateParts.push_back(segment);
		}

		CTime startDate = CTime(stoi(dateParts.at(0)), stoi(dateParts.at(1)), stoi(dateParts.at(2)), 0, 0, 0, 0);

		mysqlx::Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");

		std::vector <Student> students = fetchAllStudents(sess);
		std::vector <Teacher> teachers = fetchAllTeachers(sess);
		std::vector <Laba> labs = fetchAllLabs(sess);
		std::vector <Spec> specs = fetchAllSpecs(sess);

		std::vector<Schedule::TeacherEntry> schedule;
		schedule = getScheduler(sess, startDate, specs, students, teachers, labs);

		// cout << "-------------------------------------------------------------------------" << endl;

		cout << schedule << endl;

		/*for (auto teacherEntry : schedule) {
			cout << "teacher: " << teacherEntry.teacher << endl;
			cout << "schedule: " << endl;
			for (auto dateEntry : teacherEntry.schedule) {
				cout << "date: " << dateEntry.date << endl;

				cout << "firstShift: " << endl;
				for (auto shiftEntry : dateEntry.firstShift) {
					cout << "  " << shiftEntry.student << " " << shiftEntry.laba << endl;
				}

				cout << "secondShift: " << endl;
				for (auto shiftEntry : dateEntry.secondShift) {
					cout << "  " << shiftEntry.student << " " << shiftEntry.laba << endl;
				}
				cout << endl;
			}
			cout << endl;
		}*/

		sess.close();
	}
	catch (const mysqlx::Error& err)
	{
		std::cout << "ERROR: " << err << endl;
		return 1;
	}
	catch (std::exception& ex)
	{
		std::cout << "STD EXCEPTION: " << ex.what() << endl;
		return 2;
	}
	catch (const char* ex)
	{
		std::cout << "EXCEPTION: " << ex << endl;
		return 3;
	}
}
