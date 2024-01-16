
#include "Polymorph.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {
}

Polymorph::~Polymorph() {
}

Polymorph * Polymorph::clone() const {
	Polymorph *ans = new Polymorph(*this);
	return ans;
}

