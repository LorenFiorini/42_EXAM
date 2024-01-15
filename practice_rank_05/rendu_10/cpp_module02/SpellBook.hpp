
#pragma once

#include <map>
#include <string>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook {
private:
	SpellBook(SpellBook const & obj);
	SpellBook& operator=(SpellBook const & obj);

public:
	SpellBook();
	~SpellBook();

	std::map<std::string, ASpell *> mp;
	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const & sn);
	ASpell* createSpell(std::string const & sn);
};

// ---------------------------
