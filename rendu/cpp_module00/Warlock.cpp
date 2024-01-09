

#include "Warlock.hpp"
#include <string>
#include <iostream>

<<<<<<< HEAD

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
	
=======
Warlock::Warlock(void) {
	this->_name = "";
	this->_title = "";
}
Warlock::Warlock(Warlock const &obj) {
	*this = obj;
}
Warlock::Warlock(std::string const &name, std::string const &title) {
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
	
}
Warlock::~Warlock(void) {
	// std::cout << this->_name << "" << std::endl;
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock& Warlock::operator=(Warlock const &obj) {
	this->_name = obj._name;
	this->_title = obj._title;
	return (*this);
}
std::string const &Warlock::getName(void) const {
	return (this->_name);
}
std::string const &Warlock::getTitle(void) const {
	return (this->_title);
}

void Warlock::setTitle(std::string const &title) {
	this->_title = title;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " ;
	std::cout << this->_name << ", ";
	std::cout << this->_title << "!" << std::endl;
>>>>>>> my_main
}
