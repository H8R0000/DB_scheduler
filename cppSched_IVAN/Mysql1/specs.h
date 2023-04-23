#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

std::vector<Spec> fetchAllSpecs(mysqlx::Session& sess);