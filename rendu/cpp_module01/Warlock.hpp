
#pragma once
#include <iostream>
#include <string>
#include <map>

class Warlock {
private:
	std::string _name;
	std::string _title;
	// map<std::string, std::string> _book;

	Warlock();
	Warlock(Warlock const & obj);
	Warlock& operator=(Warlock const & obj);

public:
	Warlock(std::string const & name, std::string const & title);
	~Warlock();

	std::string const & getName() const ;
	std::string const & getTitle() const ;
	void setTitle(std::string const & title);

	void introduce() const;

	// void learnSpell(std::string spell) ;
	// void forgetSpell(std::string spell) ;
	// void launchSpell(std::string spell) ;
};
