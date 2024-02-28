#pragma once
#include <iostream>
#include "ATarget.hpp"
#include <vector>

class ATarget;
class TargetGenerator
{
	private:
		std::vector<ATarget *> vect;
		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator &operator=(TargetGenerator const &copy);
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const &type);
		ATarget* createTarget(std::string const &target);
};
