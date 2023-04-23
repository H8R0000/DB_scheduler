#pragma once

#include "connect.h"

struct Teacher
{
    int id_t;
    std::string name;
    std::string surname;
    std::string patronymic;
};

void addTeacher(struct Teacher teacher, Session& sess);

std::vector<Teacher> fetchAllTeachers(Session& sess);

void deleteTeacher(std::string id, Session& sess);