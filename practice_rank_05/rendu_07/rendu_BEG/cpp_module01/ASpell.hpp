
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;
	ASpell(void);

public:
	ASpell(ASpell const &obj);
	ASpell &operator=(ASpell const &obj);
	ASpell(std::string name, std::string effects);
	virtual ~ASpell(void);

	std::string getName(void) const;
	std::string getEffects(void) const;

	void launch(ATarget const & target) const;
	virtual ASpell *clone(void) const = 0;
};

#endif
