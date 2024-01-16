
#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string na;
	std::string ef;

	ASpell(void);

public:
	ASpell(ASpell const & obj);
	ASpell& operator=(ASpell const & obj);
	virtual ~ASpell();

	ASpell(std::string na, std::string effects);
	std::string getName(void) const;
	std::string getEffects(void) const;
	virtual ASpell * clone() const = 0;

	void launch(ATarget const & target) const;
};


/* ---------------------------- */
