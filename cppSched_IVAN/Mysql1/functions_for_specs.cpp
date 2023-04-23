#include "connect.h"

template <class T>
inline void SWAP(T& a, T& b) {
    T tmp = b; b = a; a = tmp;
}

template <typename T> //introducing template T
std::vector<T>& operator+=(std::vector<T>& m, const std::vector<T>& n) //pairs of vector n and m.
{
	m.reserve(m.size() + n.size()); // using reverse func
	m.insert(m.end(), n.begin(), n.end()); //using insert func 
	return m;            //return whole vector m 
}

std::vector<Student> fetchAllStudentsWithSpec(Session& sess, const std::string& spec) {
	std::vector<Student> vector;
	std::string table = "student";
	Schema myDb = sess.getSchema("students_db", true);
	Table myTable = myDb.getTable(table);

	RowResult myRows = myTable\
		.select("id_st", "name", "surname", "patronymic", "st", "alive", "spec", "group_name")\
		.where("spec = :spec")\
		.orderBy("spec ASC", "alive DESC")\
		.bind("spec", spec)\
		.execute();

	for (Row row : myRows.fetchAll()) {
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

std::vector<string> fetchAllLabsForSpec(Session& sess, const std::string& spec) {
	std::vector<string> labas;

	// Создаем SqlStatement с нужным запросом
	auto myRows = sess.sql("SELECT l.name FROM students_db.laba l, students_db.spec s, students_db.laba_spec ls WHERE ls.idlaba=l.idlaba AND s.id_spec=ls.id_spec AND s.name=?").bind(spec).execute();

	for (Row row : myRows.fetchAll()) {
		labas.push_back(std::string(row.get(0)));
	}

	return labas;
}