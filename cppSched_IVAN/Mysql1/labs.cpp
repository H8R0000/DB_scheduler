#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<Laba> fetchAllLabs(mysqlx::Session& sess)
{
	std::vector<Laba> laba;
	mysqlx::RowResult myRows = sess.getSchema("students_db", true).getTable("laba")
		.select("idlaba", "name", "direction").execute();

	for (mysqlx::Row row : myRows.fetchAll())
	{
		Laba LABA;
		LABA.id_laba = row.get(0);
		if (!row.get(1).isNull())
			LABA.name = std::string(row.get(1));
		if (!row.get(2).isNull())
			LABA.direction = std::string(row.get(2));
		laba.push_back(LABA);
	}

	return laba;
}

void addLaba(struct Laba laba, mysqlx::Session& sess)
{
	sess.getSchema("students_db", true).getTable("laba")
		.insert("name")
		.values(laba.name)
		.execute();
}

void deleteLaba(std::string id, mysqlx::Session& sess)
{
	sess.getSchema("students_db", true).getTable("laba")
		.remove().where("id_laba = " + id).execute();
}