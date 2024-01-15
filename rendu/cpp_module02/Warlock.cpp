
#include "Warlock.hpp"

Warlock::Warlock() {
	// std::cout << std::endl;
}
Warlock::Warlock(Warlock const & obj) {
	// std::cout << std::endl;
	*this = obj;
}
Warlock& Warlock::operator=(Warlock const & obj) {
	// std::cout << std::endl;
	_name = obj._name;
	_title = obj._title;
	return (*this);
}
Warlock::~Warlock() {
	std::cout << _name;
	std::cout << ": My job here is done!";
	std::cout << std::endl;
}

// ---------------------------

Warlock::Warlock(std::string const & name, std::string const & title)
	: _name(name), _title(title) {
	std::cout << _name;
	std::cout << ": This looks like another boring day.";
	std::cout << std::endl;
}

std::string const & Warlock::getName() const {
	return (_name);
}
std::string const & Warlock::getTitle() const {
	return (_title);
}
void Warlock::setTitle(std::string const & title)  {
	_title = title;
}
void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


// void Warlock::learnSpell(ASpell *spell) {
// 	std::string sn = spell->getName();
// 	if (mp.find(sn) == mp.end()) {
// 		mp[sn] = spell->clone();
// 	}
// }
// void Warlock::forgetSpell(std::string sn) {
// 	if (mp.find(sn) != mp.end()) {
// 		mp.erase(sn);
// 	}
// }
// void Warlock::launchSpell(std::string sn, ATarget const & target) {
// 	if (mp.find(sn) != mp.end()) {
// 		mp[sn]->launch(target);
// 	}
// }
void Warlock::learnSpell(ASpell *spell) {
	book.learnSpell(spell);
}
void Warlock::forgetSpell(std::string sn) {
	book.forgetSpell(sn);
}
void Warlock::launchSpell(std::string sn, ATarget const & target) {
	if (book.mp.find(sn) != book.mp.end()) {
		book.mp[sn]->launch(target);
	}
}