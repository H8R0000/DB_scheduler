#include "connect.h"

std::vector<Spec> fetchAllSpecs(Session& sess) {
	std::vector<Spec> specs;
	std::string table_str = "spec";
	Schema myDb = sess.getSchema("students_db", true);
	Table myTable = myDb.getTable(table_str);
	RowResult myRows = myTable.select("id_spec", "name", "priority").orderBy("priority").execute();

	for (Row row : myRows.fetchAll())
	{
		Spec spec;
		spec.id_spec = row.get(0);
		spec.name = std::string(row.get(1));
		spec.priority = int(row.get(2));

		specs.push_back(spec);
	}

	return specs;
}