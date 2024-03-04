
#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
    std::string na;
    std::string ef;

    ASpell(void);
public:
    ASpell(ASpell const & obj);
    ASpell& operator=(ASpell const & obj);
    virtual ~ASpell();
    ASpell(std::string name, std::string effects);

    std::string getName() const ;
    std::string getEffects() const ;

    virtual ASpell * clone() const = 0;

    void launch(ATarget const & spell) const ;

};


/*

std::cout << std::endl;

std::string const &

*/
