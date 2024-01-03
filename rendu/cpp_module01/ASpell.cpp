
#include "ASpell.hpp"


ASpell::ASpell(void) {
	this->_name = "";
	this->_effects = "";
}
ASpell::ASpell(ASpell const &src) {
	*this = src;
}
ASpell& ASpell::operator=(ASpell const &src) {
	this->_name = src._name;
	this->_effects = src._effects;
	return (*this);
}
ASpell::ASpell(std::string const &name, std::string const &effects) {
	_name = name;
	_effects = effects;
}
ASpell::~ASpell(void) {
	
}

std::string const &ASpell::getName(void) const {
	return (this->_name);
}
std::string const &ASpell::getEffects(void) const {
	return (this->_effects);
}

void ASpell::introduce(void) const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_effects << "!" << std::endl;
}
