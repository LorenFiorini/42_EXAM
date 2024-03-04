

/*

std::cout << std::endl;

std::string const &

*/

#include "SpellBook.hpp"


SpellBook::SpellBook(void) {
}
SpellBook::SpellBook(SpellBook const & obj) {
    *this = obj;
}
SpellBook& SpellBook::operator=(SpellBook const & obj) {
    if (this != &obj) {
        // this->mp = obj.mp;
        return (*this);
    }
    return (*this);
}
SpellBook::~SpellBook() {
}

void SpellBook::learnSpell(ASpell * spell) {
    std::string sn = spell->getName();
    if (mp.find(sn) == mp.end()) {
        mp[sn] = spell->clone();
    }
}
void SpellBook::forgetSpell(std::string const & sn) {
    if (mp.find(sn) != mp.end()) {
        delete mp.find(sn)->second;
        mp.erase(sn);
    }
}
ASpell * SpellBook::createSpell(std::string const & sn) {
    ASpell *spell = NULL;
    if (mp.find(sn) != mp.end()) {
        spell = mp[sn]->clone();
    }
    return (spell);
}
