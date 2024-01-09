
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>
# include <iostream>

class ASpell {
protected:
	std::string	_name;
	std::string	_effects;

public:
	ASpell(void);
	ASpell(ASpell const &src);
	ASpell& operator=(ASpell const &src);
	ASpell(std::string const &name, std::string const &effects);
	~ASpell(void);

	std::string const &getName(void) const;
	std::string const &getEffects(void) const;
	
	ASleep *clone(void) const = 0;
};

#endif
