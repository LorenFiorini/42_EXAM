

#include "Warlock.hpp"

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
}
