
#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget {
public:
    Dummy(void);
    ~Dummy();
    Dummy * clone() const;
};


/*

std::cout << std::endl;

std::string const &

*/
