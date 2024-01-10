
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string _type;
	ATarget(void);

public:
	ATarget(ATarget const &obj);
	ATarget &operator=(ATarget const &obj);
	ATarget(std::string type);
	virtual ~ATarget(void);
	std::string getType(void) const;
	void getHitBySpell(ASpell const &spell) const;
	virtual ATarget *clone(void) const = 0;

};

#endif
