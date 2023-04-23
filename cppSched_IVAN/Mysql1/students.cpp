#include "connect.h"

std::vector<Student> fetchAllStudents(Session& sess)
{
	std::vector <Student> vector;
	std::string table = "student";
	Schema myDb = sess.getSchema("students_db", true);
	Table myTable = myDb.getTable(table);
	RowResult myRows = myTable\
		.select("id_st", "name", "surname", "patronymic", "st", "alive", "spec", "group_name")\
		.orderBy("spec ASC", "alive DESC")\
		.execute();

	for (Row row : myRows.fetchAll())
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
		vector.push_back(STUDENT);
	}

	return vector;
}

void addStudent(struct Student student, Session& sess)
{
	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
	std::string table_str = "student";
	Schema myDb = sess.getSchema("students_db", true);

	// Accessing an existing table
	Table myTable = myDb.getTable(table_str);

	// Find a row in the SQL Table
	myTable.insert("name", "surname", "patronymic", "st", "alive", "id_group")
		.values(student.name, student.surname, student.patronymic, student.st, student.alive)
		.execute();

}

void deleteStudent(std::string id, Session& sess)
{

	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
	std::string table_str = "student";
	Schema myDb = sess.getSchema("students_db", true);

	// Accessing an existing table
	Table myTable = myDb.getTable(table_str);

	// Find a row in the SQL Table
	myTable.remove().where("id_st = " + id).execute();
}

