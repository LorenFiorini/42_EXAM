
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

<<<<<<< HEAD
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
=======
class ATarget;

class ASpell {
	protected:
		std::string _name;
		std::string _effects;

		// ASpell(void);
	public:
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const &obj);
		ASpell &operator=(ASpell const &obj);
		virtual ~ASpell(void);

		std::string getName(void) const;
		std::string getEffects(void) const;

		virtual ASpell *clone() const = 0;

		void launch(ATarget const &target) const;
>>>>>>> my_main
};

#endif
