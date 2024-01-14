
#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;

	ASpell();

public:
	ASpell(ASpell const & obj);
	ASpell& operator=(ASpell const & obj);
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();

	std::string getName() const;
	std::string getEffects() const;

	virtual ASpell *clone() const = 0;
};
