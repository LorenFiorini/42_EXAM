
#include "Warlock.hpp"


Warlock::Warlock(void) {
}
Warlock::Warlock(Warlock const & obj) {
    *this = obj;
}
Warlock& Warlock::operator=(Warlock const & obj) {
    if (this != &obj) {
        this->na = obj.na;
        this->ti= obj.ti;
        return (*this);
    }
    return (*this);
}
Warlock::~Warlock() {
    std::cout << na << ": My job here is done!" << std::endl;
}

// 4 + 

Warlock::Warlock(std::string const & name, std::string const & title) 
    : na(name), ti(title)
{
    std::cout << na << ": This looks like another boring day." << std::endl;
}

std::string const & Warlock::getName() const {
    return na;
}
std::string const & Warlock::getTitle() const {
    return ti;
}


void Warlock::setTitle(std::string const & title) {
    ti = title;
}
void Warlock::introduce() const {
    std::cout << na << ": I am " << na << ", " << ti << "!" << std::endl;

}

void Warlock::learnSpell(ASpell * spell) {
    std::string sn = spell->getName();
    if (mp.find(sn) == mp.end()) {
        mp[sn] = spell->clone();
    }
}
void Warlock::forgetSpell(std::string sn) {
    if (mp.find(sn) != mp.end()) {
        delete mp.find(sn)->second;
        mp.erase(sn);
    }
}
void Warlock::launchSpell(std::string sn, ATarget const & target) {
    if (mp.find(sn) != mp.end()) {
        mp[sn]->launch(target);
    }
}
