#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

void addStudent(struct Student student, mysqlx::Session& sess);

std::vector<Student> fetchAllStudents(mysqlx::Session& sess);

void deleteStudent(std::string id, mysqlx::Session& sess);