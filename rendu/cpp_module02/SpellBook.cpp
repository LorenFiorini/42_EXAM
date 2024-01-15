
#include "SpellBook.hpp"

SpellBook::SpellBook() {
	// std::cout << std::endl;
}
SpellBook::SpellBook(SpellBook const & obj) {
	// std::cout << std::endl;
	*this = obj;
}
SpellBook& SpellBook::operator=(SpellBook const & obj) {
	// std::cout << std::endl;
	if (this == &obj)
		return (*this);
	return (*this);
}
SpellBook::~SpellBook() {
	// std::cout << std::endl;
}

// ---------------------------

void SpellBook::learnSpell(ASpell* spell) {
	std::string sn = spell->getName();
	if (mp.find(sn) == mp.end()) {
		mp[sn] = spell->clone();
	}
}
void SpellBook::forgetSpell(std::string const & sn){
	if (mp.find(sn) != mp.end()) {
		mp.erase(sn);
	}
}
ASpell* SpellBook::createSpell(std::string const & sn) {
	ASpell *ans = NULL;

	// ans = new ASpell(mp[sn]);
	if (mp.find(sn) != mp.end()) {
		ans = mp[sn]->clone();
	}
	return (ans);
}
