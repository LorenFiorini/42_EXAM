
#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell *> _book;

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

	void learnSpell(ASpell const * spell);
	void forgetSpell(std::string spell_name);
	void launchSpell(std::string spell_name, ATarget const & target);
};

