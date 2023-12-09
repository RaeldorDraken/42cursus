#pragma once
#include<iostream>
#include"ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string	name;
		std::string	effects;
	public:
		std::string const getName();
		std::string const getEffects();
		virtual ASpell *clone() = 0;
		void	launch(ATarget const &tango) const;
		ASpell(std::string _name, std::string _effect);
		virtual ~ASpell();
};
