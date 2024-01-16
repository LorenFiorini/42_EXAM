
#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"


class Warlock {
private:
	std::string na;
	std::string ti;
	std::map< std::string , ASpell * > mp;

	Warlock(void);
	Warlock(Warlock const & obj);
	Warlock& operator=(Warlock const & obj);

public:
	Warlock(std::string const & name, std::string const & title);
	~Warlock();

	std::string const & getName(void) const;
	std::string const & getTitle(void) const;
	void setTitle(std::string const & title);
	void introduce() const;

	void learnSpell(ASpell * spell) ;
	void forgetSpell(std::string sn) ;
	void launchSpell(std::string sn, ATarget const & target) ;
};

