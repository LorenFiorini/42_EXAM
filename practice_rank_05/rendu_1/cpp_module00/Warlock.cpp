
#include "Warlock.hpp"
#include <string>
#include <iostream>


Warlock::Warlock(void)
	: _name(""), _title("") { }

Warlock::Warlock(Warlock &src)
	: _name(src._name), _title(src._title) { }

Warlock& Warlock::operator=(Warlock &src) {
	if (this != &src) {
		this->_name = src._name;
		this->_title = src._title;
	}
	return (*this);
}

Warlock::Warlock(const std::string &name, const std::string &title) 
	: _name(name), _title(title) {
	std::cout << this->_name;
	std::cout << ": This looks like another boring day.";
	std::cout << std::endl;
}

Warlock::~Warlock(void) {
	std::cout << this->_name;
	std::cout << ": My job here is done!";
	std::cout << std::endl;
}

const std::string	&Warlock::getName(void) const {
	return (this->_name);
}

const std::string	&Warlock::getTitle(void) const {
	return (this->_title);
}

void	Warlock::setTitle(const std::string &title) {
	this->_title = title;
}

void	Warlock::introduce(void) const {
	std::cout << this->_name;
	std::cout << ": I am ";
	std::cout << this->_name;
	std::cout << ", ";
	std::cout << this->_title;
	std::cout << "!";
	std::cout << std::endl;
	
}
