#pragma once

#include <vector>
#include <string>
#include <atltime.h>

using namespace std;

struct Student
{
    int id_st;
    string name;
    string surname;
    string patronymic;
    string st;
    int alive;
    string spec;
    string group_name;
};

struct Teacher
{
    int id_t;
    string name;
    string surname;
    string patronymic;
};

struct Spec
{
    int id_spec;
    string name;
    int priority;
};

struct Laba
{
    int id_laba;
    string name;
    string direction;
};

struct StudentLabs
{
    Student student;
    vector<string> labs;
};

struct Group
{
    vector<StudentLabs> studentLabs;
    Teacher teacher;
    Spec spec;
};

struct SchedulerEntry
{
    CTime date;
    vector<StudentLabs> firstShiftStudentLabs;
    vector<StudentLabs> secondShiftStudentLabs;
};