
#ifndef ASPELL_HPP
# define ASPELL_HPP

class ATarget;

#include <iostream>
#include <string>

class ASpell {
	protected:
		std::string _name;
		std::string _effects;

	public:
		ASpell(void);
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const &obj);
		ASpell &operator=(ASpell const &obj);
		virtual ~ASpell(void);

		std::string getName(void) const;
		std::string getEffects(void) const;

		void launch(ATarget const &target) const;

		virtual ASpell *clone() const = 0;
};

#endif
