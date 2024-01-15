
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
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

// ---------------------------

void TargetGenerator::learnTargetType(ATarget* target) {
	std::string tn = target->getType();
	if (mp.find(tn) == mp.end()) {
		mp[tn] = target->clone();
	}
}
void TargetGenerator::forgetTargetType(std::string const & tn){
	if (mp.find(tn) != mp.end()) {
		mp.erase(tn);
	}
}
ATarget* TargetGenerator::createTarget(std::string const & tn) {
	ATarget* ans = NULL;

	// ans = new ATarget(mp[tn]);
	if (mp.find(tn) != mp.end()) {
		ans = mp[tn]->clone();
	}
	return (ans);
}
