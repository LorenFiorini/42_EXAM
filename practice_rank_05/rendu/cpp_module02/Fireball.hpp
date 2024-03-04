
#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell {
public:
    Fireball(void);
    ~Fireball();
    Fireball * clone() const;
};


/*

std::cout << std::endl;

std::string const &

*/
