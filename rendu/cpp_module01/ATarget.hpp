
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>
# include <iostream>

class ATarget {
protected:
	std::string _type;

	ATarget();
	ATarget(ATarget const &obj);
	ATarget& operator=(ATarget const &obj);
public:
	ATarget(std::string const & type);
	virtual ~ATarget();

	std::string const &getType() const; // Reference to const string

	virtual ATarget *clone() const = 0;
};

#endif
