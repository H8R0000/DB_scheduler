#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector <Teacher> fetchAllTeachers(mysqlx::Session& sess)
{
	std::vector<Teacher> teacher;
	mysqlx::RowResult myRows = sess.getSchema("students_db", true).getTable("teacher")
		.select("id_t", "name", "surname", "patr")\
		.execute();

	for (mysqlx::Row row : myRows.fetchAll())
	{
		Teacher TEACHER;
		TEACHER.id_t = row.get(0);
		TEACHER.name = std::string(row.get(1));
		TEACHER.surname = std::string(row.get(2));
		if (!row.get(3).isNull())
			TEACHER.patronymic = std::string(row.get(3));
		teacher.push_back(TEACHER);
	}

	return teacher;
}

void addTeacher(struct Teacher teacher, mysqlx::Session& sess)
{
	sess.getSchema("students_db", true).getTable("teacher")
		.insert("name", "surname")
		.values(teacher.name, teacher.surname)
		.execute();
}

void deleteTeacher(std::string id, mysqlx::Session& sess)
{
	sess.getSchema("students_db", true).getTable("teacher")
		.remove().where("id_t = " + id).execute();
}