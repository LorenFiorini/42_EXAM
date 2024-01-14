
#include "ATarget.hpp"

ATarget::ATarget() {

}
ATarget::ATarget(ATarget const & obj) {
	*this = obj;
}
ATarget::ATarget(std::string const & type)
	: _type(type) {
	// std::cout
	// << this->_type 
	// << std::endl;
}
ATarget::~ATarget() {

}

ATarget& ATarget::operator=(ATarget const & obj) {
	this->_type = obj._type;
	return *this;
}
std::string const & ATarget::getType() const  {
	return this->_type;
}

void ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout
	<< this->_type
	<< " has been " 
	<< spell.getEffects()
	<< "!" 
	<< std::endl;
}
