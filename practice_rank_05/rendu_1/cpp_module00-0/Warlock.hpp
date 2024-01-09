
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
class Warlock {
private:
	std::string	name;
	std::string	title;

	Warlock(void);
	Warlock(Warlock &src);
	Warlock& operator=(Warlock &src);

public:
	const std::string getName(void) const;
	const std::string getTitle(void) const;

	void setTitle(const std::string title);

	Warlock(std::string name, std::string title);
	~Warlock(void);

	void introduce(void) const;
};

#endif
