
#pragma once


#include <string>
#include <iostream>

class T {
private:

protected:

public:
	T();
	T(T const & obj);
	T& operator=(T const & obj);
	~T();

};

// ---------------------------

#include "T.hpp"

T::T() {
	// std::cout << std::endl;
}
T::T(T const & obj) {
	// std::cout << std::endl;
	*this = obj;
}
T& T::operator=(T const & obj) {
	// std::cout << std::endl;
	return (*this);
}
T::~T() {
	// std::cout << std::endl;
}

// ---------------------------

