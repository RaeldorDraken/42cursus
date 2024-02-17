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
		void	forgetTargetType(const std::string &_name);
		ATarget *createTarget(const std::string &_name);
	private:
		std::map<std::string, ATarget*> list;
};

#endif
