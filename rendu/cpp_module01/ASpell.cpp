
#include "ASpell.hpp"

ASpell::ASpell(void) : _name(""), _effects("") { }

ASpell::ASpell(ASpell const &src) {
	*this = src;
}

ASpell& ASpell::operator=(ASpell rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}
	return (*this);
}

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {
	// std::cout << this->_name << ": This looks like another boring day." << std::endl;

}

ASpell::~ASpell(void) {
	// std::cout << this->_name << ": My job here is done!" << std::endl;
}


std::string ASpell::getName(void) const {
	return (this->_name);
}

std::string ASpell::getEffects(void) const {
	return (this->_effects);
}

void launch(ATarget const &target) const {
	// std::cout << this->_type << ": This looks like another boring day." << std::endl;
	target.getHitBySpell(this);
}
