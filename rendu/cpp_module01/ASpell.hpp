
#pragma once


#include <string>
#include <iostream>
#include "ATarget.hpp"
class ATarget;

class ASpell {
protected:
	std::string _na;
	std::string _ef;

	ASpell();
	ASpell(ASpell const & obj);
	ASpell& operator=(ASpell const & obj);

public:
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();

	std::string getName() const ;
	std::string getEffects() const ;

	virtual ASpell *clone() const = 0;

	void launch(ATarget const & target) const;
};

