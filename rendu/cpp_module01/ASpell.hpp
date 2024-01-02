
#ifndef ASPELL_HPP
# define ASPELL_HPP
# include "ATarget.hpp"
# include <iostream>
# include <string>


class ASpell {
protected:
	std::string	_name;
	std::string	_effects;

public:
	ASpell(void);
	ASpell(ASpell const &src);
	ASpell& operator=(ASpell const rhs);
	ASpell(std::string const &name, std::string const &effects);
	virtual ~ASpell(void);

	std::string getName(void) const;
	std::string getEffects(void) const;
	void launch(ATarget const &target) const;
	
	virtual ASpell* clone(void) const = 0;
	
};

#endif
