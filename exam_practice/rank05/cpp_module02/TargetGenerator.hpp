#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include<map>
#include"ATarget.hpp"

class TargetGenerator
{
	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void	learnTargetType(ATarget *target);
		void	forgetTargetType(const std::string &targetName);
		ATarget *createTarget(const std::string &targetName);
	private:
		std::map<std::string, ATarget *> _targets;
};

#endif
