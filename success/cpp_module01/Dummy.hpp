
#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class Dummy : public ATarget {
	public:
		Dummy(void);
		Dummy(Dummy const &obj);
		Dummy &operator=(Dummy const &obj);
		virtual ~Dummy(void);

		virtual ATarget *clone() const;
};

#endif
