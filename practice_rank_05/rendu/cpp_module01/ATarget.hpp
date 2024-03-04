
#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
    std::string ty;

    ATarget(void);
public:
    ATarget(ATarget const & obj);
    ATarget& operator=(ATarget const & obj);
    virtual ~ATarget();
    ATarget(std::string name);

    std::string const & getType() const ;

    virtual ATarget * clone() const = 0;

    void getHitBySpell(ASpell const & spell) const ;
};


/*

std::cout << std::endl;

std::string const &

*/
