
#pragma once

#include <map>
#include <string>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
private:
	std::string _name;
	std::string _title;
	// std::map<std::string, ASpell *> mp;
	SpellBook book;

	Warlock();
	Warlock(Warlock const & obj);
	Warlock& operator=(Warlock const & obj);

public:
	Warlock(std::string const & name, std::string const & title);
	~Warlock();

	std::string const & getName() const ;
	std::string const & getTitle() const ;
	void setTitle(std::string const & title) ;
	void introduce() const;


	void learnSpell(ASpell *spell) ;
	void forgetSpell(std::string sn) ;
	void launchSpell(std::string sn, ATarget const & target) ;
};

