#pragma once

#include<iostream>
#include"ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string	type;
	public:
		std::string const &getType() const;
		virtual ATarget	*clone() = 0;
		void	getHitBySpell(ASpell &src);
		ATarget(std::string _type);
		virtual ~ATarget();
};
