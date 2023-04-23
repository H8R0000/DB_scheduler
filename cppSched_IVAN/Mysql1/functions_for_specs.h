#pragma once

#include <mysqlx/xdevapi.h>
#include "entities.h"

template <class T>
inline void SWAP(T& a, T& b) {
	T tmp = b; b = a; a = tmp;
}

template <typename T> //introducing template T
std::vector<T>& operator+=(std::vector<T>& m, const std::vector<T>& n) //pairs of vector n and m.
{
	m.reserve(m.size() + n.size()); // using reverse func
	m.insert(m.end(), n.begin(), n.end()); //using insert func 

	return m;            //return whole vector m 
}

std::vector<Student> fetchAllStudentsWithSpec(mysqlx::Session& sess, const std::string& spec);
std::vector<std::string> fetchAllLabsForSpec(mysqlx::Session& sess, const std::string& spec);