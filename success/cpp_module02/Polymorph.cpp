
#include "Polymorph.hpp"

Polymorph::Polymorph() {
	// std::cout << std::endl;
	_na = "Polymorph";
	_ef = "turned into a critter";
}
Polymorph::~Polymorph() {
	// std::cout << std::endl;
}

Polymorph *Polymorph::clone() const {
	Polymorph *ans;
	ans = new Polymorph(*this);
	return (ans);
}
