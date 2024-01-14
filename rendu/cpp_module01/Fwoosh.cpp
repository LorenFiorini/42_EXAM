
#include "Fwoosh.hpp"

// Fwoosh::Fwoosh() : _name ("Fwoosh"), _effects("fwooshed") { }
Fwoosh::Fwoosh() {
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";
}
Fwoosh::~Fwoosh() { }


Fwoosh *Fwoosh::clone() const {
	Fwoosh *ans;

	ans = new Fwoosh(*this);
	return ans;
}
