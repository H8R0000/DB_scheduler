#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<Student> fetchAllStudents(mysqlx::Session& sess)
{
	std::vector <Student> student;
	mysqlx::RowResult myRows = sess.getSchema("students_db", true).getTable("student")\
		.select("id_st", "name", "surname", "patronymic", "st", "alive", "spec", "group_name")\
		.orderBy("spec ASC", "alive DESC")\
		.execute();

	for (mysqlx::Row row : myRows.fetchAll())
	{
		Student STUDENT;
		STUDENT.id_st = row.get(0);
		STUDENT.name = std::string(row.get(1));
		STUDENT.surname = std::string(row.get(2));
		if (!row.get(3).isNull())
			STUDENT.patronymic = std::string(row.get(3));
		STUDENT.st = std::string(row.get(4));
		STUDENT.alive = row.get(5);
		if (!row.get(6).isNull())
			STUDENT.spec = std::string(row.get(6));
		if (!row.get(7).isNull())
			STUDENT.group_name = std::string(row.get(7));
		student.push_back(STUDENT);
	}

	return student;
}

void addStudent(struct Student student, mysqlx::Session& sess)
{
	sess.getSchema("students_db", true).getTable("student")
		.insert("name", "surname", "patronymic", "st", "alive", "id_group")
		.values(student.name, student.surname, student.patronymic, student.st, student.alive)
		.execute();
}

void deleteStudent(std::string id, mysqlx::Session& sess)
{
	sess.getSchema("students_db", true).getTable("student")
		.remove().where("id_st = " + id).execute();
}