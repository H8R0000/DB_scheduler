#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

// void addGroup(struct Group group, mysqlx::Session& sess);

// void fetchAllGroups(mysqlx::Session& sess);

void deleteGroup(std::string id, mysqlx::Session& sess);