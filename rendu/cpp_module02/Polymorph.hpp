
#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"


class Polymorph : public ASpell {
public:
	Polymorph(void);
	~Polymorph();

	Polymorph * clone() const;
};


/* ---------------------------- */
