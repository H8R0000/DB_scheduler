#pragma once

#include <atltime.h>
#include <nlohmann/json.hpp>
#include <mysqlx/xdevapi.h>

#include "entities.h"

using json = nlohmann::json;

namespace Schedule
{
    /*struct ShiftEntry
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
    };*/

    void to_json(json& j, const ShiftEntry& s) {
        j = json{ {"student", s.student}, {"laba", s.laba} };
    }

    void to_json(json& j, const DateEntry& d) {
        j = json{ {"date", d.date}, {"firstShift", d.firstShift}, {"secondShift", d.secondShift} };
    }

    void to_json(json& j, const TeacherEntry& t) {
        j = json{ {"teacher", t.teacher}, {"schedule", t.schedule} };
    }
}

std::vector<Schedule::TeacherEntry> getScheduler(mysqlx::Session& sess, CTime& startDate, std::vector<Spec>& specs, std::vector<Student>& students, \
    std::vector<Teacher>& teachers, std::vector<Laba>& labs);

std::ostream& operator << (std::ostream& os, const std::vector<Schedule::TeacherEntry>& v)
{
    json j = v;

    os << j << endl;

    return os;
}
