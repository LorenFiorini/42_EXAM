
#include "Warlock.hpp"

Warlock::Warlock(void)
	: name(""), title("")
{

}

Warlock::Warlock(Warlock &src)
	: name(src.name), title(src.title) { }

Warlock& Warlock::operator=(Warlock &src) {
	if (this != &src) {
		this->name = src.name;
		this->title = src.title;
	}
	return (*this);
}

Warlock::Warlock(std::string name, std::string title) 
	: name(name), title(title) {
	std::cout << this->name;
	std::cout << ": This looks like another boring day.";
	std::cout << std::endl;
}

Warlock::~Warlock(void) {
	std::cout << this->name;
	std::cout << ": My job here is done!";
	std::cout << std::endl;
}


const std::string	Warlock::getName(void) const {
	return (this->name);
}

const std::string	Warlock::getTitle(void) const {
	return (this->title);
}

void	Warlock::setTitle(const std::string title) {
	this->title = title;
}

void	Warlock::introduce(void) const {
	std::cout << this->name;
	std::cout << ": I am ";
	std::cout << this->name;
	std::cout << ", ";
	std::cout << this->title;
	std::cout << "!";
	std::cout << std::endl;
	
}
