#include"TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) : _targets()
{}

TargetGenerator::~TargetGenerator(void)
{
	std::map<std::string, ATarget *>::iterator it;
	for (it = this->_targets.begin(); it != this->_targets.end(); ++it)
		delete it->second;
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	this->_targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string &targetName)
{
	if (this->_targets.find(targetName) != this->_targets.end())
		delete this->_targets[targetName];
	this->_targets.erase(targetName);
}

ATarget *TargetGenerator::createTarget(const std::string &targetName)
{
	if (this->_targets.find(targetName) != this->_targets.end())
		return (this->_targets[targetName]);
	return (NULL);
}
