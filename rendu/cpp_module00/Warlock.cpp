
#include "Warlock.hpp"

Warlock::Warlock() {
	// std::cout << std::endl;
}
Warlock::Warlock(Warlock const & obj) {
	// std::cout << std::endl;
	*this = obj;
}
Warlock& Warlock::operator=(Warlock const & obj) {
	// std::cout << std::endl;
	_name = obj._name;
	_title = obj._title;
	return (*this);
}
Warlock::~Warlock() {
	std::cout << _name;
	std::cout << ": My job here is done!";
	std::cout << std::endl;
}

// ---------------------------

Warlock::Warlock(std::string const & name, std::string const & title)
	: _name(name), _title(title) {
	std::cout << _name;
	std::cout << ": This looks like another boring day.";
	std::cout << std::endl;
}

std::string const & Warlock::getName() const {
	return (_name);
}
std::string const & Warlock::getTitle() const {
	return (_title);
}
void Warlock::setTitle(std::string const & title)  {
	_title = title;
}
void Warlock::introduce() const {
	std::cout << _name;
	std::cout << ": I am ";
	std::cout << _name;
	std::cout << ", ";
	std::cout << _title;
	std::cout << "!";
	std::cout << std::endl;
}
