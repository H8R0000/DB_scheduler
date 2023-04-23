#pragma once

#include "connect.h"

struct Laba
{
    int id_laba;
    std::string name;
    std::string direction;
};

void addLaba(struct Laba laba, Session& sess);

std::vector<Laba> fetchAllLabs(Session& sess);

void deleteLaba(std::string id, Session& sess);