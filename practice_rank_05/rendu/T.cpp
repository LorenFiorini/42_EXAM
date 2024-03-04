
#pragma once

#include <string>
#include <iostream>

class T {
private:
    std::string a;
protected:

public:
    T(void);
    T(T const & obj);
    T& operator=(T const & obj);
    ~T();
};


/*

std::cout << std::endl;

std::string const &

*/

#include "T.hpp"


T::T(void) {
}
T::T(T const & obj) {
    *this = obj;
}
T& T::operator=(T const & obj) {
    if (this != &obj) {
        this->a = obj.a;
        return (*this);
    }
    return (*this);
}
T::~T() {
}

// 4 + 
