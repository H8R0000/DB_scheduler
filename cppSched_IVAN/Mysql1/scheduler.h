#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<std::string> getScheduler(mysqlx::Session& sess, std::vector<Spec>& specs, std::vector<Student>& students, \
    std::vector<Teacher>& teachers, std::vector<Laba>& labs);