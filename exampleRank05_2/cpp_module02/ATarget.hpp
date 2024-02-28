#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string attribute;
	public:
		ATarget();
		ATarget(std::string const &attribute);
		virtual ~ATarget();
		ATarget(ATarget const &copy);
		ATarget &operator=(ATarget const &copy);
		std::string const &getType() const;
		virtual ATarget *clone() const = 0;
		void	getHitBySpell(ASpell const &spell) const;
};
