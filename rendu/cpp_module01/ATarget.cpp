
#include "ATarget.hpp"

ATarget::ATarget(void) : _type("") { }

ATarget::ATarget(ATarget const &src) {
	*this = src;
}

ATarget& ATarget::operator=(ATarget rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

ATarget::ATarget(std::string const &type) : _type(type) { }

ATarget::~ATarget(void) {
}


std::string ATarget::getType(void) const {
	return (this->_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << "!"<< std::endl;

}
