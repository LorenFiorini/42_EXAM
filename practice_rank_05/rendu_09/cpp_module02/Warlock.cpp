
#include "Warlock.hpp"

Warlock::Warlock() {

}
Warlock::Warlock(Warlock const & obj) {
	*this = obj;
}
Warlock::Warlock(std::string const & name, std::string const & title)
: _name(name), _title(title) {
	std::cout
	<< this->_name 
	<< ": This looks like another boring day." 
	<< std::endl;
}
Warlock::~Warlock() {
	std::cout
	<< this->_name 
	<< ": My job here is done!" 
	<< std::endl;

	_book.clear();
}

Warlock& Warlock::operator=(Warlock const & obj) {
	this->_name = obj._name;
	this->_title = obj._title;
	return *this;
}
std::string const & Warlock::getName() const  {
	return this->_name;
}
std::string const & Warlock::getTitle() const  {
	return this->_title;
}
void Warlock::setTitle(std::string const & title) {
	this->_title = title;
}

void Warlock::introduce() const {
	std::cout
	<< this->_name 
	<< ": I am " 
	<< this->_name 
	<< ", " 
	<< this->_title
	<< "!" 
	<< std::endl;

}


void Warlock::learnSpell(ASpell * spell) {
	std::string spell_name = spell->getName();
	if (_book.find(spell_name) == _book.end()) {
		_book[spell_name] = spell->clone();
	}
}
void Warlock::forgetSpell(std::string spell_name) {
	if (_book.find(spell_name) != _book.end()) {
		// delete _book.find(spell_name)->second;
		_book.erase(spell_name);
	}

}
void Warlock::launchSpell(std::string spell_name, ATarget const & target) {
	if (_book.find(spell_name) != _book.end()) {
		_book[spell_name]->launch(target);
	}

}

