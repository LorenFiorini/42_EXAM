

#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private:
	std::map<std::string, ATarget* > _targets;
	TargetGenerator(TargetGenerator const & obj);
	TargetGenerator& operator=(TargetGenerator const & obj);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const & target_type);
	ATarget* createTarget(std::string const & target_type);
};


#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
}
TargetGenerator::TargetGenerator(TargetGenerator const & obj) {
	*this = obj;
}
TargetGenerator::~TargetGenerator() {
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

	ans = new ATarget(target_type);
	return ans;
}
