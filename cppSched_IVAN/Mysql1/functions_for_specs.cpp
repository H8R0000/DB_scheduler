#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<Student> fetchAllStudentsWithSpec(mysqlx::Session& sess, const std::string& spec) {
	std::vector<Student> student;
	mysqlx::RowResult myRows = sess.getSchema("students_db", true).getTable("student")
		.select("id_st", "name", "surname", "patronymic", "st", "alive", "spec", "group_name")
		.where("spec = :spec")
		.orderBy("spec ASC", "alive DESC")
		.bind("spec", spec)
		.execute();

	for (mysqlx::Row row : myRows.fetchAll()) {
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

std::vector<std::string> fetchAllLabsForSpec(mysqlx::Session& sess, const std::string& spec) {
	std::vector<std::string> labs;

	// Создаем SqlStatement с нужным запросом
	auto myRows = sess.sql("SELECT l.name FROM students_db.laba l, students_db.spec s, students_db.laba_spec ls WHERE ls.idlaba=l.idlaba AND s.id_spec=ls.id_spec AND s.name=?").bind(spec).execute();

	for (mysqlx::Row row : myRows.fetchAll()) {
		labs.push_back(std::string(row.get(0)));
	}

	return labs;
}