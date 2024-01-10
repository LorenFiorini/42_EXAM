
#include "ASpell.hpp"

ASpell::ASpell(void) {
	return ;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {
	return ;
}

ASpell::ASpell(ASpell const &obj) {
	*this = obj;
	return ;
}

ASpell::~ASpell(void) {
	return ;
}

ASpell &ASpell::operator=(ASpell const &obj) {
	if (this != &obj) {
		this->_name = obj.getName();
		this->_effects = obj.getEffects();
	}
	return (*this);
}

std::string ASpell::getName(void) const {
	return (this->_name);
}

std::string ASpell::getEffects(void) const {
	return (this->_effects);
}

void ASpell::launch(ATarget const & target) const {
	target.getHitBySpell((*this));
	return ;
}

