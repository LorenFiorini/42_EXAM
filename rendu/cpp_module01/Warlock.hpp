
#pragma once

#include <iostream>
#include <string>

class Warlock {
private:
	std::string na;
	std::string ti;

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
};


/* ---------------------------- */
