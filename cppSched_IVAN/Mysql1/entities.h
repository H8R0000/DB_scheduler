#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include <atltime.h>

using namespace std;
using json = nlohmann::json;

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

namespace Schedule
{
    struct ShiftEntry
    {
        string student;
        string laba;
    };

    struct DateEntry
    {
        string date;
        vector<ShiftEntry> firstShift;
        vector<ShiftEntry> secondShift;
    };

    struct TeacherEntry
    {
        string teacher;
        vector<DateEntry> schedule;
    };

    /*void to_json(json& j, const ShiftEntry& s) {
        j = json{ {"student", s.student}, {"laba", s.laba} };
    }

    void to_json(json& j, const DateEntry& d) {
        j = json{ {"date", d.date}, {"firstShift", d.firstShift}, {"secondShift", d.secondShift} };
    }

    void to_json(json& j, const TeacherEntry& t) {
        j = json{ {"teacher", t.teacher}, {"schedule", t.schedule} };
    }*/
}