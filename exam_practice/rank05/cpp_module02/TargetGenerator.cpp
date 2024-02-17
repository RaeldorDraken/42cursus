#include"TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) : list()
{}

TargetGenerator::~TargetGenerator(void)
{}

void TargetGenerator::learnTargetType(ATarget *target)
{
	this->list[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string &targetName)
{
	if (this->list.find(targetName) != this->list.end())
		delete this->list[targetName];
	this->list.erase(targetName);
}

ATarget *TargetGenerator::createTarget(const std::string &targetName)
{
	if (this->list.find(targetName) != this->list.end())
		return (this->list[targetName]);
	return (NULL);
}
