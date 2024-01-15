
#pragma once

#include <map>
#include <string>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator {
private:
	TargetGenerator(TargetGenerator const & obj);
	TargetGenerator& operator=(TargetGenerator const & obj);

public:
	TargetGenerator();
	~TargetGenerator();

	std::map<std::string, ATarget *> mp;

	// ATarget* createSpell(std::string const & sn);
	void learnTargetType(ATarget* target) ;
	void forgetTargetType(std::string const & tn) ;
	ATarget* createTarget(std::string const & tn) ;
};

// ---------------------------


