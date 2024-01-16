
#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"


class Dummy : public ATarget {
public:
	Dummy(void);
	~Dummy();

	Dummy * clone() const;
};


/* ---------------------------- */
