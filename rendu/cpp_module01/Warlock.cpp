
#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName(void) const
{
	return (this->_name);
}

std::string const &Warlock::getTitle(void) const
{
	return (this->_title);
}

void Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

void Warlock::introduce(void) const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	this->_spells[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator it;

	it = this->_spells.find(spellName);
	if (it != this->_spells.end())
		this->_spells.erase(it);
}

void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	std::map<std::string, ASpell *>::iterator it;

	it = this->_spells.find(spellName);
	if (it != this->_spells.end())
		it->second->launch(target);
}

