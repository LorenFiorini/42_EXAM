
#include "Polymorph.hpp"


Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {
}
Polymorph::~Polymorph() {
}

Polymorph * Polymorph::clone() const {
    return (new Polymorph());
}
