
#include "TargetGenerator.hpp"

/*
	std::cout << "Constructor" << std::endl;
	std::cout << "Destructor" << std::endl;
*/


TargetGenerator::TargetGenerator(void) {
}
TargetGenerator::TargetGenerator(TargetGenerator const & obj) {
	*this = obj;
}
TargetGenerator& TargetGenerator::operator=(TargetGenerator const & obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}
TargetGenerator::~TargetGenerator() {
}


/* 4 + .*/
// void TargetGenerator::learnSpell(ATarget * spell) {
// 	std::string sn = spell->getName();
// 	if (mp.find(sn) == mp.end()) {
// 		mp[sn] = spell->clone();
// 	}
// }
// void TargetGenerator::forgetSpell(std::string const & sn) {
// 	if (mp.find(sn) != mp.end()) {
// 		mp.erase(sn);
// 	}
// }
// ATarget * TargetGenerator::createSpell(std::string const & sn) {
// 	ATarget * ans = NULL;
// 	if (mp.find(sn) != mp.end()) {
// 		ans = mp[sn]->clone();
// 	}
// 	return ans;
// }

void TargetGenerator::learnTargetType(ATarget * target) {
	std::string tn = target->getType();
	if (mp.find(tn) == mp.end()) {
		mp[tn] = target->clone();
	}
}
void TargetGenerator::forgetTargetType(std::string const & tn) {
	if (mp.find(tn) != mp.end()) {
		mp.erase(tn);
	}
}
ATarget * TargetGenerator::createTarget(std::string const & tn) {
	ATarget * ans = NULL;
	if (mp.find(tn) != mp.end()) {
		ans = mp[tn]->clone();
	}
	return ans;
}
