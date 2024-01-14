

#pragma once
#include <iostream>
#include <string>
#include <map>

class SpellBook {
private:
	std::map<std::string, ASpell * > _book;
	SpellBook();
	SpellBook(SpellBook const & obj);
	SpellBook& operator=(SpellBook const & obj);

public:
	~SpellBook();

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const & spell_name);
	ASpell* createSpell(std::string const & spell_name);
};


#include "SpellBook.hpp"

SpellBook::SpellBook() {
}
SpellBook::SpellBook(SpellBook const & obj) {
	*this = obj;
}
SpellBook::~SpellBook() {
}



void SpellBook::learnSpell(ASpell* spell) {
	if (_book.find(spell->getType()) == _book.end()) {
		_book[spell->getType()] = spell->clone();
	}
}
void SpellBook::forgetSpell(std::string const & spell_name) {
	if (_book.find(spell_name) != _book.end()) {
		_book.erase(spell_name);
	}
}
ASpell* SpellBook::createSpell(std::string const & spell_name) {
	ASpell* ans;

	ans = new ASpell(spell_name);
	return ans;
}
