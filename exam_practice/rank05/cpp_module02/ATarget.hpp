#ifndef ATARGET_HPP
#define ATARGET_HPP

#include<string>
#include<iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget(std::string const &_type);
		ATarget(ATarget const &src);
		virtual ~ATarget(void);
		ATarget &operator=(ATarget const &rhs);
		std::string const &getType(void) const;
		virtual ATarget *clone(void) const = 0;
		void	getHitBySpell(ASpell const &src) const;
	protected:
		std::string type;
};

#endif
