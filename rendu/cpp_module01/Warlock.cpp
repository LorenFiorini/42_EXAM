

#include "Warlock.hpp"

Warlock::Warlock(void) : _name(""), _title("") { }

Warlock::Warlock(Warlock &src) {
	*this = src;
}


Warlock &Warlock::operator=(Warlock &src)
{
	this->_name = src._name;
	this->_title = src._title;
	return *this;
}

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << this->_name;
	std::cout << ": This looks like another boring day." << std::endl;
}


Warlock::~Warlock(void) {
	std::cout << this->_name;
	std::cout << ": My job here is done!" << std::endl;
}


std::string const	&Warlock::getName(void) const {
	return (this->_name);
}

std::string const	&Warlock::getTitle(void) const {
	return (this->_title);
}

void Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}


void Warlock::introduce(void) const {
	std::cout << this->_name;
	std::cout << ": I am ";
	std::cout << this->_name;
	std::cout << ", ";
	std::cout << this->_title;
	std::cout << "!" << std::endl;

}