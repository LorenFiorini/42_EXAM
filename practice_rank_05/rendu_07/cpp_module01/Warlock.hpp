
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include <map>
# include "ASpell.hpp"

class Warlock {
private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell *> _spells;
	
	Warlock(void);
	Warlock(Warlock const &obj);
	Warlock &operator=(Warlock const &obj);


public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock(void);

	std::string const &getName(void) const;
	std::string const &getTitle(void) const;

	void setTitle(std::string const &title);

	void introduce(void) const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget const &target);
};

#endif
