
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

class Warlock {
private:
<<<<<<< HEAD
	std::string	_name;
	std::string	_title;

	Warlock(void);
	Warlock(Warlock &src);
	Warlock& operator=(Warlock &src);

public:
	const std::string &getName(void) const;
	const std::string &getTitle(void) const;

	void setTitle(const std::string &title);

	Warlock(const std::string &name, const std::string &title);
	~Warlock(void);

	void introduce(void) const;
=======
	std::string _name;
	std::string _title;
	Warlock(void);
	Warlock(Warlock const &obj);
	Warlock& operator=(Warlock const &obj);
public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock(void);

	std::string const &getName(void) const;
	std::string const &getTitle(void) const;

	void setTitle(std::string const &title);
	
	void introduce() const;
>>>>>>> my_main
};

#endif
