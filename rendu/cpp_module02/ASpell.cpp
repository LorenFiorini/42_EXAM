
#include "ASpell.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


ASpell::ASpell(void) {
}
ASpell::ASpell(ASpell const & obj) {
	*this = obj;
}
ASpell& ASpell::operator=(ASpell const & obj) {
	if (this != &obj) {
		this->na = obj.na;
		this->ef = obj.ef;
	}
	return (*this);
}
ASpell::~ASpell() {
}


/* 4 + .*/
ASpell::ASpell(std::string name, std::string effects) : na(name), ef(effects) {
}

std::string ASpell::getName(void) const {
	return na;
}
std::string ASpell::getEffects(void) const {
	return ef;
}


void ASpell::launch(ATarget const & target) const {
	target.getHitBySpell(*this);
}
