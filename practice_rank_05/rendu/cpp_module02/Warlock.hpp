
#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"

// class SpellBook;

class Warlock {
private:
    std::string na;
    std::string ti;
    // std::map< std::string , ASpell * > mp;
    SpellBook book;

    Warlock(void);
    Warlock(Warlock const & obj);
    Warlock& operator=(Warlock const & obj);

public:
    Warlock(std::string const & name, std::string const & title);
    ~Warlock();

    std::string const & getName() const ;
    std::string const & getTitle() const ;
    void setTitle(std::string const & title);
    void introduce() const;

    void learnSpell(ASpell * spell) ;
    void forgetSpell(std::string sn) ;
    void launchSpell(std::string sn, ATarget const & target) ;
};


/*

std::cout << std::endl;

std::string const &

*/
