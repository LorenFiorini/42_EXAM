
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
}
TargetGenerator::TargetGenerator(TargetGenerator const & obj) {
	*this = obj;
}
TargetGenerator::~TargetGenerator() {
}

TargetGenerator& TargetGenerator::operator=(TargetGenerator const & obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (_targets.find(target->getType()) == _targets.end()) {
		_targets[target->getType()] = target->clone();
	}
}
void TargetGenerator::forgetTargetType(std::string const & target_type) {
	if (_targets.find(target_type) != _targets.end()) {
		_targets.erase(target_type);
	}
}
ATarget* TargetGenerator::createTarget(std::string const & target_type) {
	ATarget* ans;

	ans = _targets[target_type]->clone();
	return ans;
}
