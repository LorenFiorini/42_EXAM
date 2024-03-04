
#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
// #include "Warlock.hpp"


class TargetGenerator {
private:
    TargetGenerator(TargetGenerator const & obj);
    TargetGenerator& operator=(TargetGenerator const & obj);

public:
    TargetGenerator(void);
    ~TargetGenerator();

    std::map< std::string , ATarget * > mp;

    void learnTargetType(ATarget * target) ;
    void forgetTargetType(std::string const & sn) ;
    ATarget * createTarget(std::string const & sn) ;
    // void launchSpell(std::string sn, ATarget const & target) ;
};


/*

std::cout << std::endl;

std::string const &

*/
