
#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"


class Fireball : public ASpell {
public:
	Fireball(void);
	~Fireball();

	Fireball * clone() const;
};


/* ---------------------------- */
