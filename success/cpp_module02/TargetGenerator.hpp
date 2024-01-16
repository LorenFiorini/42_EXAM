
#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator {
private:
	TargetGenerator(TargetGenerator const & obj);
	TargetGenerator& operator=(TargetGenerator const & obj);

public:
	TargetGenerator(void);
	~TargetGenerator();
	std::map< std::string , ATarget * > mp;

	// void learnSpell(ATarget * spell);
	// void forgetSpell(std::string const & sn);
	// ATarget* createSpell(std::string const & sn);
	void learnTargetType(ATarget * target) ;
	void forgetTargetType(std::string const & tn) ;
	ATarget * createTarget(std::string const & tn) ;
};


/* ---------------------------- */
