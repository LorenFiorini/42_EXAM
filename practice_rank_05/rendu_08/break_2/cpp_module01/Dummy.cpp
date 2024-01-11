
#include "Dummy.hpp"

Dummy::Dummy() {
	this->_type = "Target Practice Dummy";
	// std::cout << this->_type << std::endl; // Debug
}
Dummy::~Dummy() {
	// std::cout << "delete " << this->_type << std::endl; // Debug
}
ATarget *Dummy::clone() const {
	ATarget *cpy;

	cpy = new Dummy(*this);
	return (cpy);
}
