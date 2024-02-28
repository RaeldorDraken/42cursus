#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		std::vector<ATarget *>::iterator iter = this->vect.begin();
		for (; iter != vect.end(); iter++)
		{
			if ((*iter)->getType() == target->getType())
				return ;
		}
		this->vect.push_back(target->clone());
	}
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	std::vector<ATarget *>::iterator iter = vect.begin();
	for (; iter != vect.end(); iter++)
	{
		if ((*iter)->getType() == type)
		{
			delete *iter;
			this->vect.erase(iter);
			return ;
		}
	}
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	std::vector<ATarget *>::iterator iter = vect.begin();
	for (; iter != vect.end(); iter++)
	{
		if ((*iter)->getType() == target)
		{
			return (*iter);
		}
	}
	return (NULL);
}
