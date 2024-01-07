

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class Fwoosh : public ASpell {
	public:
		Fwoosh(void);
		Fwoosh(Fwoosh const &obj);
		Fwoosh &operator=(Fwoosh const &obj);
		virtual ~Fwoosh(void);

		virtual ASpell *clone() const;
};

#endif
