

#include "Fireball.hpp"

Fireball::Fireball() {
	// std::cout << std::endl;
	_na = "Fireball";
	_ef = "burnt to a crisp";
}
Fireball::~Fireball() {
	// std::cout << std::endl;
}

Fireball *Fireball::clone() const {
	Fireball *ans;
	ans = new Fireball(*this);
	return (ans);
}
