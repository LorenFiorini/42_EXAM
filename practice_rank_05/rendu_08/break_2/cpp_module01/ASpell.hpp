
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>
# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;

	ASpell();
public:
	ASpell(ASpell const &obj);
	ASpell& operator=(ASpell const &obj);
	ASpell(std::string const & name, std::string const & effects);
	virtual ~ASpell();

	std::string getName() const;
	std::string getEffects() const;

	virtual ASpell *clone() const = 0;

	void launch(ATarget const & target) const;
};

#endif
