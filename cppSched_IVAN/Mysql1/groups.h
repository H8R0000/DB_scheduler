#pragma once

#include "connect.h"
#include "students.h"
#include "teachers.h"
#include "labs.h"
#include "specs.h"

struct Group
{
    std::vector<Student> students;
    std::vector<string> labas;
    Teacher teacher;
    Spec spec;
};

// void addGroup(struct Group group, Session& sess);

// void fetchAllGroups(Session& sess);

void deleteGroup(std::string id, Session& sess);