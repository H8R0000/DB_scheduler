#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<Spec> fetchAllSpecs(mysqlx::Session& sess) {
	std::vector<Spec> spec;
	mysqlx::RowResult myRows = sess.getSchema("students_db", true).getTable("spec")
		.select("id_spec", "name", "priority").orderBy("priority").execute();

	for (mysqlx::Row row : myRows.fetchAll())
	{
		Spec SPEC;
		SPEC.id_spec = row.get(0);
		SPEC.name = std::string(row.get(1));
		SPEC.priority = int(row.get(2));

		spec.push_back(SPEC);
	}

	return spec;
}