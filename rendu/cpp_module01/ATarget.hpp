
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string _type;

	public:
		ATarget(void);
		ATarget(std::string type);
		ATarget(ATarget const &obj);
		ATarget &operator=(ATarget const &obj);
		virtual ~ATarget(void);

		std::string getType(void) const;

		virtual ATarget *clone() const = 0;

		void getHitBySpell(ASpell spell) const;
};

#endif
