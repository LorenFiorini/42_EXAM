
#include "ATarget.hpp"


ATarget::ATarget(void) {
	this->_type = "";
}
ATarget::ATarget(ATarget const &src) {
	*this = src;
}
ATarget& ATarget::operator=(ATarget const &src) {
	this->_type = src._type;
	return (*this);
}
ATarget::ATarget(std::string const &type) {
	_type = type;
}
ATarget::~ATarget(void) {
	
}

std::string const &ATarget::getType(void) const {
	return (this->_type);
}

void ATarget::introduce(void) const {
	std::cout << this->_type << ": I am " << this->_type << ", " << this->_effects << "!" << std::endl;
}
