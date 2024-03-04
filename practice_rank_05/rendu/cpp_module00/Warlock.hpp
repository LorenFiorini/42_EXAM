
#pragma once

#include <string>
#include <iostream>

class Warlock {
private:
    std::string na;
    std::string ti;

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
};


/*

std::cout << std::endl;

std::string const &

*/
