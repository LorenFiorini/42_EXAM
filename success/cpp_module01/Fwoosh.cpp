
#include "Fwoosh.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed!") {
}

Fwoosh::~Fwoosh() {
}

Fwoosh * Fwoosh::clone() const {
	Fwoosh *ans = new Fwoosh(*this);
	return ans;
}

