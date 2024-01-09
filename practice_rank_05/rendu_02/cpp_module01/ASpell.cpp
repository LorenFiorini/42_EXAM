
#include "ASpell.hpp"

ASpell::ASpell(void) : _name(""), _effects("")
{
	std::cout << "ASpell default constructor called" << std::endl;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
	std::cout << "ASpell constructor called" << std::endl;
}

ASpell::ASpell(ASpell const& src)
{
	std::cout << "ASpell copy constructor called" << std::endl;
	*this = src;
}

ASpell::~ASpell(void)
{
	std::cout << "ASpell destructor called" << std::endl;
}

ASpell& ASpell::operator=(ASpell const& rhs)
{
	std::cout << "ASpell assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_effects = rhs._effects;
	}
	return (*this);
}