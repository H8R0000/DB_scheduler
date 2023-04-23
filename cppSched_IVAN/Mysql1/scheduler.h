#pragma once

#include "connect.h"

std::vector<std::string> getScheduler(Session& sess, std::vector<Spec>& specs, std::vector <Student>& students, \
    std::vector <Teacher>& teachers, std::vector <Laba>& labs);