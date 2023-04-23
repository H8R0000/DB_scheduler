#pragma once

#include "connect.h"

struct Spec
{
    int id_spec;
    std::string name;
    int priority;
};

std::vector<Spec> fetchAllSpecs(Session& sess);