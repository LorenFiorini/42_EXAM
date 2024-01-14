

#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
private:
	SpellBook(SpellBook const & obj);
	SpellBook& operator=(SpellBook const & obj);

public:
	SpellBook();
	~SpellBook();

	std::map<std::string, ASpell * > _book;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const & spell_name);
	ASpell* createSpell(std::string const & spell_name);
};

