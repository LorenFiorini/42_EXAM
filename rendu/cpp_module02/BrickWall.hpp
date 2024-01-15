#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget {
public:
	BrickWall();
	~BrickWall();
	BrickWall *clone() const;
};

// ---------------------------

