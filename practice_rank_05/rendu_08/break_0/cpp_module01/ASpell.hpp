
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>
# include <iostream>

class ASpell {
private:
	std::string _name;
	std::string _effects;

	ASpell();
	ASpell(ASpell const &obj);
	ASpell& operator=(ASpell const &obj);
public:
	ASpell(std::string name, std::string effects);
	~ASpell();

	std::string getName() const;
	std::string getEffects() const;

	ASpell *clone() const = 0;
};

#endif
