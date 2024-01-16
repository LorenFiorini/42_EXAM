
#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"


class Fwoosh : public ASpell {
public:
	Fwoosh(void);
	~Fwoosh();

	Fwoosh * clone() const;
};


/* ---------------------------- */
