

#include "Warlock.hpp"

Warlock::Warlock(void) {
	this->_name = "";
	this->_title = "";
}
Warlock::Warlock(Warlock const &obj) {
	*this = obj;
}
Warlock::Warlock(std::string const &name, std::string const &title) {
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
	
}
// Warlock::~Warlock(void) {
// 	// std::cout << this->_name << "" << std::endl;
// 	std::cout << this->_name << ": My job here is done!" << std::endl;
// }
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}


Warlock& Warlock::operator=(Warlock const &obj) {
	this->_name = obj._name;
	this->_title = obj._title;
	return (*this);
}
std::string const &Warlock::getName(void) const {
	return (this->_name);
}
std::string const &Warlock::getTitle(void) const {
	return (this->_title);
}

void Warlock::setTitle(std::string const &title) {
	this->_title = title;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am "  << this->_name << ", " << this->_title << "!" << std::endl;
}

// 


void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(SpellName));
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook[SpellName]->launch(target);
}
