

#include "Dummy.hpp"

Dummy::Dummy() {
	// std::cout << std::endl;
	_ty = "Target Practice Dummy";
}
Dummy::~Dummy() {
	// std::cout << std::endl;
}

Dummy *Dummy::clone() const {
	Dummy *ans;
	ans = new Dummy(*this);
	return (ans);
}
