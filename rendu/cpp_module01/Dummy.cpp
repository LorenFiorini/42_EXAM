
#include "Dummy.hpp"

Dummy::Dummy()
	// : _type("Target Practice Dummy") {
{
	this->_type = "Target Practice Dummy";

}
Dummy::~Dummy() {

}
Dummy *Dummy::clone() const {
	Dummy *ans;

	ans = new Dummy();
	return ans;
}
