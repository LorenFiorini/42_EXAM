
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>
# include <iostream>
# include "ASpell.hpp"

class ASpell;


class ATarget {
protected:
	std::string _type;

	ATarget();
public:
	ATarget(ATarget const &obj);
	ATarget& operator=(ATarget const &obj);
	ATarget(std::string const & type);
	virtual ~ATarget();

	std::string const &getType() const; // Reference to const string

	virtual ATarget *clone() const = 0;
	void getHitBySpell(ASpell const & spell) const ;
};

#endif
