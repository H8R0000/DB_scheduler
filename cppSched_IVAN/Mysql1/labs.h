#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

void addLaba(struct Laba laba, mysqlx::Session& sess);

std::vector<Laba> fetchAllLabs(mysqlx::Session& sess);

void deleteLaba(std::string id, mysqlx::Session& sess);