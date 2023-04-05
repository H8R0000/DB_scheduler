#pragma once

#include <iostream>
#include <mysqlx/xdevapi.h>

using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;

struct student
{
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string st;
    int alive;
    int id_group;
};

struct teacher
{
    std::string name;
    std::string surname;
};

struct laba
{
    std::string name;
    int id_block;
};

struct group
{
    int YearForm;
    int id_spec;
};

void add_st(struct student teacher);
void add_t(struct teacher teacher);
void add_group(struct group group);
void add_lab(struct laba laba);

void fetchAll_st();
void fetchAll_teachers();
void fetchAll_labs();
void fetchAll_groups();

void delete_lab(std::string id);
void delete_st(std::string id);
void delete_t(std::string id);
void delete_group(std::string id);
