
#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"
class ASpell;

class ATarget {
protected:
	std::string _ty;

	ATarget();
	ATarget(ATarget const & obj);
	ATarget& operator=(ATarget const & obj);

public:
	ATarget(std::string name);
	virtual ~ATarget();

	std::string const & getType() const ;

	virtual ATarget *clone() const = 0;

	void getHitBySpell(ASpell const & spell) const;
};

