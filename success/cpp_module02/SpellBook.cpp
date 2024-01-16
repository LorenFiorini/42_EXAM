
#include "SpellBook.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


SpellBook::SpellBook(void) {
}
SpellBook::SpellBook(SpellBook const & obj) {
	*this = obj;
}
SpellBook& SpellBook::operator=(SpellBook const & obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}
SpellBook::~SpellBook() {
}


/* 4 + .*/
void SpellBook::learnSpell(ASpell * spell) {
	std::string sn = spell->getName();
	if (mp.find(sn) == mp.end()) {
		mp[sn] = spell->clone();
	}
}
void SpellBook::forgetSpell(std::string const & sn) {
	if (mp.find(sn) != mp.end()) {
		mp.erase(sn);
	}
}
ASpell * SpellBook::createSpell(std::string const & sn) {
	ASpell * ans = NULL;
	if (mp.find(sn) != mp.end()) {
		ans = mp[sn]->clone();
	}
	return ans;
}
