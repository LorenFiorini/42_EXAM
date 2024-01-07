
#ifndef ASPELL_HPP
# define ASPELL_HPP

class ATarget;

#include <iostream>
#include <string>

class ASpell {
	private:
		std::string _name;
		std::string _effects;

	public:
		ASpell(void);
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &obj);
		ASpell &operator=(ASpell const &obj);
		virtual ~ASpell(void);

		std::string const &getName(void) const;
		std::string const &getEffects(void) const;

		void launch(ATarget const &target) const;

		virtual ASpell *clone() const = 0;
};

#endif
