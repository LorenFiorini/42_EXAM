
#include "ATarget.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


ATarget::ATarget(void) {
}
ATarget::ATarget(ATarget const & obj) {
	*this = obj;
}
ATarget& ATarget::operator=(ATarget const & obj) {
	if (this != &obj) {
		this->na = obj.na;
	}
	return (*this);
}
ATarget::~ATarget() {
}


/* 4 + .*/
ATarget::ATarget(std::string name) : na(name) {
}

std::string const & ATarget::getType(void) const {
	return na;
}

void ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << na << " has been " << spell.getEffects() << std::endl;
}
