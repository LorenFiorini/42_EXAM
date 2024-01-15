

#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell {
public:
	Fireball();
	~Fireball();
	Fireball *clone() const;
};

// ---------------------------


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
