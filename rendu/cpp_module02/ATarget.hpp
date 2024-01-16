
#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string na;

	ATarget(void);

public:
	ATarget(ATarget const & obj);
	ATarget& operator=(ATarget const & obj);
	virtual ~ATarget();

	ATarget(std::string na);
	std::string const & getType(void) const;
	virtual ATarget * clone() const = 0;

	void getHitBySpell(ASpell const & spell)const;
};


/* ---------------------------- */
