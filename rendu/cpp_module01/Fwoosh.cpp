
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	// std::cout << std::endl;
	_na = "Fwoosh";
	_ef = "fwooshed";
}
Fwoosh::~Fwoosh() {
	// std::cout << std::endl;
}

Fwoosh *Fwoosh::clone() const {
	Fwoosh *ans;
	ans = new Fwoosh(*this);
	return (ans);
}
