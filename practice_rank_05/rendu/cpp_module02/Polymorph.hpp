
#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell {
public:
    Polymorph(void);
    ~Polymorph();
    Polymorph * clone() const;
};


/*

std::cout << std::endl;

std::string const &

*/
