
#ifndef ATARGET_HPP
# define ATARGET_HPP
# include "ASpell.hpp"
# include <iostream>
# include <string>

class ATarget {
protected:
	std::string	_type;

	ATarget(void);
	ATarget(ATarget const &src);
	ATarget& operator=(ATarget const rhs);

public:
	ATarget(std::string const &type);
	virtual ~ATarget(void);

	std::string getType(void) const;	
	void getHitBySpell(ASpell const &spell) const;

	virtual ATarget*	clone(void) const = 0;

};

#endif
