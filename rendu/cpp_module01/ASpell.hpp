


#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <string>
# include <iostream>

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
		ASpell(void);

	public:
		ASpell(ASpell &src);
		ASpell	&operator=(ASpell &src);
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell(void);

		std::string	getName(void) const;
		std::string	getEffects(void) const;

		virtual ASpell	*clone() const = 0;

		void launch(ATarget const &target) const;
};

#endif
