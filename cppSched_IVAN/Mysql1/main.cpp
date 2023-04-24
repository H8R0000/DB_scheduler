﻿#include <iostream>
#include <mysqlx/xdevapi.h>
#include <atltime.h>
#include "entities.h"
#include "students.h"
#include "teachers.h"
#include "labs.h"
#include "specs.h"
#include "scheduler.h"

using ::std::cout;
using ::std::endl;

int main()
{
	try
	{
		CTime startDate = CTime(2023, 9, 1, 0, 0, 0, 0);

		mysqlx::Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");

		std::vector <Student> students = fetchAllStudents(sess);
		std::vector <Teacher> teachers = fetchAllTeachers(sess);
		std::vector <Laba> labs = fetchAllLabs(sess);
		std::vector <Spec> specs = fetchAllSpecs(sess);

		std::vector<std::string> getOut;
		getOut = getScheduler(sess, startDate, specs, students, teachers, labs);

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
