
#include "ASpell.hpp"

ASpell::ASpell() {
}
ASpell::ASpell(ASpell const & obj) {
	*this = obj;
}
ASpell& ASpell::operator=(ASpell const & obj) {
	_na = obj._na;
	_ef = obj._ef;
	return (*this);
}
ASpell::~ASpell() {
}

// ---------------------------

ASpell::ASpell(std::string name, std::string effects)
	: _na(name), _ef(effects) {
}

std::string ASpell::getName() const {
	return (_na);
}
std::string ASpell::getEffects() const {
	return (_ef);
}

void ASpell::launch(ATarget const & target) const {
	target.getHitBySpell(*this);
}
