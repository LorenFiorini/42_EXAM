

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

