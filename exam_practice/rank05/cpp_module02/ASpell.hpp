#ifndef ASPELL_HPP
#define ASPELL_HPP

#include<string>
#include<iostream>
#include"ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell(std::string const &_name, std::string const &_effects);
		ASpell(ASpell const &src);
		virtual ~ASpell(void);
		ASpell &operator=(ASpell const &rhs);
		std::string const	&getName(void) const;
		std::string const	&getEffects(void) const;
		virtual ASpell	*clone(void) const = 0;
		void	launch(ATarget const &tango) const;
	protected:
		std::string	name;
		std::string	effects;
};

#endif
