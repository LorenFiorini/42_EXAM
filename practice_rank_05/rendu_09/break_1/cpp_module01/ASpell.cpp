
#include "ASpell.hpp"

ASpell::ASpell() {

}
ASpell::ASpell(ASpell const & obj) {
	*this = obj;
}
ASpell::ASpell(std::string name, std::string effects)
	: _name(name), _effects(effects) {
	// std::cout
	// << std::endl;
}
ASpell::~ASpell() {
	// std::cout
	// << std::endl;
}

ASpell& ASpell::operator=(ASpell const & obj) {
	this->_name = obj._name;
	this->_effects = obj._effects;
	return *this;
}
std::string ASpell::getName() const  {
	return this->_name;
}
std::string ASpell::getEffects() const  {
	return this->_effects;
}

void ASpell::launch(ATarget const & target) {
	target.getHitBySpell(*this);
}
