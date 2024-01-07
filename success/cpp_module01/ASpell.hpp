
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

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
};

#endif
