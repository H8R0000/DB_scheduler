#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

void addTeacher(struct Teacher teacher, mysqlx::Session& sess);

std::vector<Teacher> fetchAllTeachers(mysqlx::Session& sess);

void deleteTeacher(std::string id, mysqlx::Session& sess);