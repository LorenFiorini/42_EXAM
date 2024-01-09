
#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>
# include <iostream>

class ATarget {
protected:
	std::string	_type;

public:
	ATarget(void);
	ATarget(ATarget const &src);
	ATarget& operator=(ATarget const &src);
	ATarget(std::string const &type);
	~ATarget(void);

	std::string const &getType(void) const;
	
	ASleep *clone(void) const = 0;
};

#endif
