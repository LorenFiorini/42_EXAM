
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>
# include <iostream>

class ASpell {
private:
	std::string	_name;
	std::string	_effects;

	ASpell(void);
	ASpell(ASpell &src);
	ASpell& operator=(ASpell &src);

public:
	const std::string &getName(void) const;
	const std::string &getEffects(void) const;

	void setTitle(const std::string &title);

	ASpell(const std::string &name, const std::string &title);
	~ASpell(void);

	void introduce(void) const;
};

#endif
