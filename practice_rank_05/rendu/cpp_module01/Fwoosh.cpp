
#include "Fwoosh.hpp"


Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {
}
Fwoosh::~Fwoosh() {
}

Fwoosh * Fwoosh::clone() const {
    return (new Fwoosh());
}
