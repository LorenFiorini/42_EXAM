
#pragma once
#include <iostream>
#include <string>

class Warlock {
private:
	std::string _name;
	std::string _title;

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
};
