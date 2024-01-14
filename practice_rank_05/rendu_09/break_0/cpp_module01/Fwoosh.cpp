
#include "Fwoosh.hpp"


Fwoosh::Fwoosh()
	// : _name("Fwoosh"), _effects("Target Practice Dummy") {
		{
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";

}
Fwoosh::~Fwoosh() {

}
Fwoosh *Fwoosh::clone() const {
	Fwoosh *ans;

	ans = new Fwoosh();
	return ans;
}
