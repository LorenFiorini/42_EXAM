
#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator(void) {
}
TargetGenerator::TargetGenerator(TargetGenerator const & obj) {
    *this = obj;
}
TargetGenerator& TargetGenerator::operator=(TargetGenerator const & obj) {
    if (this != &obj) {
        // this->mp = obj.mp;
        return (*this);
    }
    return (*this);
}
TargetGenerator::~TargetGenerator() {
}

void TargetGenerator::learnTargetType(ATarget * target) {
    std::string sn = target->getType();
    if (mp.find(sn) == mp.end()) {
        mp[sn] = target->clone();
    }
}
void TargetGenerator::forgetTargetType(std::string const & sn) {
    if (mp.find(sn) != mp.end()) {
        delete mp.find(sn)->second;
        mp.erase(sn);
    }
}
ATarget * TargetGenerator::createTarget(std::string const & sn) {
    ATarget *target = NULL;
    if (mp.find(sn) != mp.end()) {
        target = mp[sn]->clone();
    }
    return (target);
}
