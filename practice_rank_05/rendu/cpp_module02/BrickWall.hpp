
#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget {
public:
    BrickWall(void);
    ~BrickWall();
    BrickWall * clone() const;
};


/*

std::cout << std::endl;

std::string const &

*/

