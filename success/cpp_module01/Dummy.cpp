
#include "Dummy.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


Dummy::Dummy(void) : ATarget("Target Practice Dummy") {
}

Dummy::~Dummy() {
}

Dummy * Dummy::clone() const {
	Dummy *ans = new Dummy(*this);
	return ans;
}

