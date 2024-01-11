
#include "Warlock.hpp"

Warlock::Warlock() {}
Warlock::Warlock(Warlock const &obj) {
	*this = obj;
}
Warlock::Warlock(std::string const & name, std::string const & title) {
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock() {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock& Warlock::operator=(Warlock const &obj) {
	this->_name = obj._name; //obj.getName();
	this->_title = obj._title; //obj.getTitle();
	return (*this);
}
std::string const & Warlock::getName() const {
	return this->_name;
}
std::string const & Warlock::getTitle() const {
	return this->_title;
}
void Warlock::setTitle(std::string const & title) {
	this->_title = title;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
