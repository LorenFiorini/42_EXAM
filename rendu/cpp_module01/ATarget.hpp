
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget {
	private:
		std::string _type;

	public:
		ATarget(void);
		ATarget(std::string const &type);
		ATarget(ATarget const &obj);
		ATarget &operator=(ATarget const &obj);
		virtual ~ATarget(void);

		std::string const &getType(void) const;

		virtual ATarget *clone() const = 0;

		void getHitBySpell(ASpell const &spell) const;
};

#endif
