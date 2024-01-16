
#include "Fireball.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {
}

Fireball::~Fireball() {
}

Fireball * Fireball::clone() const {
	Fireball *ans = new Fireball(*this);
	return ans;
}

