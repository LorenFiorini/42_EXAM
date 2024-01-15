
#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {
	return ;
}

Fwoosh::Fwoosh(Fwoosh const &obj) : ASpell(obj) {
	return ;
}

Fwoosh &Fwoosh::operator=(Fwoosh const &obj) {
	if (this != &obj) {
		this->_name = obj._name;
		this->_effects = obj._effects;
	}
	return (*this);
}

Fwoosh::~Fwoosh(void) {
	return ;
}

ASpell *Fwoosh::clone(void) const {
	return (new Fwoosh());
}
