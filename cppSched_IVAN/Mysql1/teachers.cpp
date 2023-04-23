#include "connect.h"

std::vector <Teacher> fetchAllTeachers(Session& sess)
{
	std::vector<Teacher> teacher;
	std::string table = "teacher";
	Schema myDb = sess.getSchema("students_db", true);
	Table myTable = myDb.getTable(table);
	RowResult myRows = myTable.select("id_t", "name", "surname", "patr")\
		.execute();

	for (Row row : myRows.fetchAll())
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

void addTeacher(struct Teacher teacher, Session& sess)
{
	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
	std::string table_str = "teacher";
	Schema myDb = sess.getSchema("students_db", true);

	// Accessing an existing table
	Table myTable = myDb.getTable(table_str);

	// Find a row in the SQL Table
	myTable.insert("name", "surname")
		.values(teacher.name, teacher.surname)
		.execute();

}

void deleteTeacher(std::string id, Session& sess)
{
	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
	std::string table_str = "teacher";
	Schema myDb = sess.getSchema("students_db", true);

	// Accessing an existing table
	Table myTable = myDb.getTable(table_str);

	// Find a row in the SQL Table
	myTable.remove().where("id_t = " + id).execute();
}