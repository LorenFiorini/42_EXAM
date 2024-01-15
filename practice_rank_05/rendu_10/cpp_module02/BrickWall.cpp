
#include "BrickWall.hpp"

BrickWall::BrickWall() {
	// std::cout << std::endl;
	_ty = "Inconspicuous Red-brick Wall";
}
BrickWall::~BrickWall() {
	// std::cout << std::endl;
}

BrickWall *BrickWall::clone() const {
	BrickWall *ans;
	ans = new BrickWall(*this);
	return (ans);
}
