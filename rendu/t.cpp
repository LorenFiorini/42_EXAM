
#pragma once

#include <iostream>
#include <string>

class T {
private:

protected:

public:
	T(void);
	T(T const & obj);
	T& operator=(T const & obj);
	~T();
};


/* ---------------------------- */

#include "T.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


T::T(void) {
}
T::T(T const & obj) {
	*this = obj;
}
T& T::operator=(T const & obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}
T::~T() {
}


/* 4 + .*/
