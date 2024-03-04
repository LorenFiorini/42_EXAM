
#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
// #include "Warlock.hpp"


class SpellBook {
private:
    SpellBook(SpellBook const & obj);
    SpellBook& operator=(SpellBook const & obj);

public:
    SpellBook(void);
    ~SpellBook();

    std::map< std::string , ASpell * > mp;

    void learnSpell(ASpell * spell) ;
    void forgetSpell(std::string const & sn) ;
    ASpell * createSpell(std::string const & sn) ;
    // void launchSpell(std::string sn, ATarget const & target) ;
};


/*

std::cout << std::endl;

std::string const &

*/
