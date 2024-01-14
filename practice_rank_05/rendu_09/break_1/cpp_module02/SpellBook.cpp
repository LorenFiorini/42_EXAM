
#include "SpellBook.hpp"

SpellBook::SpellBook() {

}
SpellBook::SpellBook(SpellBook const & obj) {
	*this = obj;
}
SpellBook::~SpellBook() {
	
}

SpellBook& SpellBook::operator=(SpellBook const & obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}



void SpellBook::learnSpell(ASpell* spell) {
	if (_book.find(spell->getName()) == _book.end()) {
		_book[spell->getName()] = spell->clone();
	}
}
void SpellBook::forgetSpell(std::string const & spell_name) {
	if (_book.find(spell_name) != _book.end()) {
		_book.erase(spell_name);
	}
}
ASpell* SpellBook::createSpell(std::string const & spell_name) {
	ASpell* ans;

	ans = _book[spell_name]->clone();
	return ans;
}
