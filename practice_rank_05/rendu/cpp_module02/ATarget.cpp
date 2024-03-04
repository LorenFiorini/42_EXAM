
#include "ATarget.hpp"


ATarget::ATarget(void) {
}
ATarget::ATarget(ATarget const & obj) {
    *this = obj;
}
ATarget& ATarget::operator=(ATarget const & obj) {
    if (this != &obj) {
        this->ty = obj.ty;
        return (*this);
    }
    return (*this);
}
ATarget::~ATarget() {
}

// 4 + 

ATarget::ATarget(std::string name) 
    : ty(name)
{
}

std::string const & ATarget::getType() const {
    return ty;
}

void ATarget::getHitBySpell(ASpell const & spell) const {
    std::cout << ty;
    std::cout << " has been ";
    std::cout << spell.getEffects();
    std::cout << "!";
    std::cout << std::endl;
}
