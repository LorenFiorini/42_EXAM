
#include "ATarget.hpp"

ATarget::ATarget() {
}
ATarget::ATarget(ATarget const & obj) {
	*this = obj;
}
ATarget& ATarget::operator=(ATarget const & obj) {
	_ty = obj._ty;
	return (*this);
}
ATarget::~ATarget() {
}

// ---------------------------

ATarget::ATarget(std::string name)	: _ty(name) {
}

std::string const & ATarget::getType() const {
	return (_ty);
}

void ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << _ty;
	std::cout << " has been ";
	std::cout << spell.getEffects();
	std::cout << "!";
	std::cout << std::endl;
}
