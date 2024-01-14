
#include "ASpell.hpp"

ASpell::ASpell() {
	// std::cout << this->_name << "" << std::endl;

}
ASpell::ASpell(ASpell const & obj) {
	*this = obj;
}
ASpell::ASpell(std::string name, std::string effects)
: _name(name), _effects(effects) {
}
ASpell::~ASpell() {
}

ASpell& ASpell::operator=(ASpell const & obj) {
	this->_name = obj._name;
	this->_effects = obj._effects;
	return *this;

}
std::string ASpell::getName() const {
	return this->_name;
}
std::string ASpell::getEffects() const {
	return this->_effects;
}
