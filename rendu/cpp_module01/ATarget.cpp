<<<<<<< HEAD
=======

#include "ATarget.hpp"

// ATarget::ATarget(void) : _type("")
// {

// }
ATarget::ATarget(std::string type) : _type(type)
{

}

ATarget & ATarget::operator=(ATarget const & obj)
{
	this->_type = obj.getType();
	return (*this);
}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget::~ATarget(void)
{

}

std::string ATarget::getType() const
{
	return (this->_type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const
// void	ATarget::getHitBySpell(ASpell spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}

// ATarget* ATarget::clone() const 
// {
// 	return (new ATarget(*this));
// }

>>>>>>> my_main
