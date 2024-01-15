
#include "ATarget.hpp"

ATarget::ATarget(void) {
	return ;
}

ATarget::ATarget(std::string type) : _type(type) {
	return ;
}

ATarget::ATarget(ATarget const &obj) {
	*this = obj;
	return ;
}

ATarget::~ATarget(void) {
	return ;
}

ATarget &ATarget::operator=(ATarget const &obj) {
	if (this != &obj) {
		this->_type = obj._type;
	}
	return (*this);
}

std::string ATarget::getType(void) const {
	return (this->_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
	return ;
}

