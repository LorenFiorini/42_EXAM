
#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {
	return ;
}

Dummy::Dummy(Dummy const &obj) : ATarget(obj) {
	return ;
}

Dummy::~Dummy(void) {
	return ;
}

Dummy &Dummy::operator=(Dummy const &obj) {
	if (this != &obj) {
		this->_type = obj._type;
	}
	return (*this);
}

ATarget *Dummy::clone(void) const {
	return (new Dummy(*this));
}
