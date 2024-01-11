
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";
	// std::cout << this->_name << ", " << this->_effects << std::endl;
}
Fwoosh::~Fwoosh() {
	// std::cout << "delete " << this->_name << ", " << this->_effects << std::endl;
}
ASpell *Fwoosh::clone() const {
	ASpell *cpy;

	cpy = new Fwoosh(*this);
	return (cpy);
}
