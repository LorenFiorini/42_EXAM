
#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"


class BrickWall : public ATarget {
public:
	BrickWall(void);
	~BrickWall();

	BrickWall * clone() const;
};


/* ---------------------------- */
