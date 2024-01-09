
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

<<<<<<< HEAD
class Warlock {
private:
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

class Warlock {

	private :
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();
		std::string _name;
		std::string _title;
		std::map < std::string, ASpell * > _SpellBook;

	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & str);
		void	introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, ATarget const & target);
>>>>>>> my_main
};

#endif
