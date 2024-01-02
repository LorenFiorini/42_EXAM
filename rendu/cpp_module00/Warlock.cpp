
#include "Warlock.hpp"

Warlock::Warlock(void) : _name(""), _title("") { }

Warlock::Warlock(Warlock const &src) {
	*this = src;
}

Warlock& Warlock::operator=(Warlock rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return (*this);
}

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;

}

Warlock::~Warlock(void) {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName(void) const {
	return this->_name;
}
std::string const &Warlock::getTitle(void) const {
	return this->_title;
}
void	Warlock::setTitle(std::string const &title) {
	this->_title = title;
}

void	Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
