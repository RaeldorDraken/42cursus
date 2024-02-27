#include"TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) : list()
{}

TargetGenerator::~TargetGenerator(void)
{
	std::map<std::string, ATarget *>::iterator it;
	std::map<std::string, ATarget *>::iterator it_end = list.end();

	for (it = list.begin(); it != it_end; it++)
		delete it->second;
	list.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
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
