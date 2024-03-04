
#include "Fireball.hpp"


Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {
}
Fireball::~Fireball() {
}

Fireball * Fireball::clone() const {
    return (new Fireball());
}
