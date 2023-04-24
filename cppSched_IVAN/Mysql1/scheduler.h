#pragma once

#include <atltime.h>
#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<SchedulerTeacherEntry> getScheduler(mysqlx::Session& sess, CTime& startDate, std::vector<Spec>& specs, std::vector<Student>& students, \
    std::vector<Teacher>& teachers, std::vector<Laba>& labs);