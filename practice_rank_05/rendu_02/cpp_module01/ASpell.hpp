
#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>
# include <iostream>


class ASpell {
	protected:
		std::string _name;
		std::string _effects;
		ASpell(void);               // Constructor
		ASpell(ASpell const& src);  // Copy Constructor
		ASpell& operator=(ASpell const& rhs);  // Assignation operator
	public:
		ASpell(std::string name, std::string effects);  // Constructor
		~ASpell(void);                                  // Destructor

		std::string getName(void);
		std::string getEffects(void);

		virtual ASpell* clone(void) const = 0;
};

#endif


