
#include "Polymorph.hpp"


Polymorph::Polymorph() {
	this->_name = "Polymorph";
	this->_effects = "turned into a critter";

}
Polymorph::~Polymorph() {

}
Polymorph *Polymorph::clone() const {
	Polymorph *ans;

	ans = new Polymorph();
	return ans;
}
