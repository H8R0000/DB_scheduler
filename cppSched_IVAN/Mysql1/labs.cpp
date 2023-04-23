#include "connect.h"

std::vector<Laba> fetchAllLabs(Session& sess)
{
	std::vector<Laba> vector;
	std::string table_str = "laba";
	Schema myDb = sess.getSchema("students_db", true);
	Table myTable = myDb.getTable(table_str);
	RowResult myRows = myTable.select("idlaba", "name", "direction").execute();

	for (Row row : myRows.fetchAll())
	{
		Laba LABA;
		LABA.id_laba = row.get(0);
		if (!row.get(1).isNull())
			LABA.name = std::string(row.get(1));
		if (!row.get(2).isNull())
			LABA.direction = std::string(row.get(2));
		vector.push_back(LABA);
	}

	return vector;
}

void addLaba(struct Laba laba, Session& sess)
{
	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
	std::string table_str = "laba";
	Schema myDb = sess.getSchema("students_db", true);

	// Accessing an existing table
	Table myTable = myDb.getTable(table_str);

	// Find a row in the SQL Table
	myTable.insert("name")
		.values(laba.name)
		.execute();
}

void deleteLaba(std::string id, Session& sess)
{

	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
	std::string table_str = "laba";
	Schema myDb = sess.getSchema("students_db", true);

	// Accessing an existing table
	Table myTable = myDb.getTable(table_str);

	// Find a row in the SQL Table
	myTable.remove().where("id_laba = " + id).execute();
}