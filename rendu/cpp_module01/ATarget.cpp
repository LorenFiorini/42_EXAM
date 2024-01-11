
#include "ATarget.hpp"

ATarget::ATarget() { }
ATarget::ATarget(ATarget const &obj) { *this = obj; }
ATarget::ATarget(std::string const & type) : _type(type) { }
ATarget::~ATarget() { }

ATarget& ATarget::operator=(ATarget const &obj) {
	this->_type = obj._type;
	return *this;
}
std::string const & ATarget::getType() const {return this->_type; }

// virtual ATarget *clone() const = 0;
