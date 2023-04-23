#include <mysqlx/xdevapi.h>
#include "entities.h"

//void addGroup(struct Group group, mysqlx::Session& sess)
//{
//	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
//	std::string table_str = "group";
//	Schema myDb = sess.getSchema("students_db", true);
//
//	// Accessing an existing table
//	Table myTable = myDb.getTable(table_str);
//
//	// Find a row in the SQL Table
//	myTable.insert("YearForm", "id_spec")
//		.values(group.YearForm, group.id_spec)
//		.execute();
//}

//void deleteGroup(std::string id, Session& sess)
//{
//	// Session sess("mysqlx://root:Zxcqwe7931@127.0.0.1");
//	std::string table_str = "group";
//	Schema myDb = sess.getSchema("students_db", true);
//
//	// Accessing an existing table
//	Table myTable = myDb.getTable(table_str);
//
//	// Find a row in the SQL Table
//	myTable.remove().where("id_g = " + id).execute();
//}