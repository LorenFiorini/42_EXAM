
#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell {
public:
    Fwoosh(void);
    ~Fwoosh();
    Fwoosh * clone() const;
};


/*

std::cout << std::endl;

std::string const &

*/
