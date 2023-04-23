#pragma once

#include "connect.h"

struct Student
{
    int id_st;
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string st;
    int alive;
    std::string spec;
    std::string group_name;
}; 

void addStudent(struct Student student, Session& sess);

std::vector<Student> fetchAllStudents(Session& sess);

void deleteStudent(std::string id, Session& sess);