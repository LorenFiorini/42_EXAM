
#include "ASpell.hpp"

// ASpell::ASpell(void) : _name(""), _effects("")
// {

// }

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}

ASpell & ASpell::operator=(ASpell const & obj)
{
	this->_name = obj.getName();
	this->_effects = obj.getEffects();
	return (*this);
}

ASpell::ASpell(ASpell const & obj)
{
	*this = obj;
}

ASpell::~ASpell(void)
{

}

std::string ASpell::getName() const
{
	return (this->_name);
}

std::string ASpell::getEffects() const
{
	return (this->_effects);
}

void ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}


// ASpell *ASpell::clone() const
// {
// 	return (new ASpell(*this));
// }
