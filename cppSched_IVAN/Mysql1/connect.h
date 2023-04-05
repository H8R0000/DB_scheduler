#pragma once

#include <iostream>
#include <mysqlx/xdevapi.h>
#include <vector>

using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;

struct student
{
    int id_st;
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string st;
    int alive;
    int id_group;
    //int id_labg;
    std::string spec;
    std::string group_name;
    
};

struct teacher
{
    int id_t;
    std::string name;
    std::string surname;
    std::string patronymic;
    int id_labg;
};

struct laba
{
    int id_laba;
    std::string name;
    std::string labs_direction;
    int id_block;
};

struct group
{
    int YearForm;
    int id_spec;
};

template <class T>
inline void SWAP(T& a, T& b) {
    T tmp = b; b = a; a = tmp;
}

void add_st(struct student student);
void add_t(struct teacher teacher);
void add_group(struct group group);
void add_lab(struct laba laba);

void fetchAll_st(std::vector <student>& vector);
void fetchAll_t(std::vector <teacher>& vector);

void fetchAll_labs(std::vector <laba>& vector);

void fetchAll_groups();

void delete_lab(std::string id);
void delete_st(std::string id);
void delete_t(std::string id);
void delete_group(std::string id);

std::vector<std::string> get_Scheduler();