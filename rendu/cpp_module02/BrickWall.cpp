

#include "BrickWall.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall") {
}

BrickWall::~BrickWall() {
}

BrickWall * BrickWall::clone() const {
	BrickWall *ans = new BrickWall(*this);
	return ans;
}

