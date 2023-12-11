#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include<iostream>
#include<map>
#include"ASpell.hpp"
#include"ATarget.hpp"

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		std::map<std::string, ASpell*> spellList;
	public:
		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void	setTitle(std::string const &_title);
		void	introduce(void) const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spell, ATarget const &target);
		Warlock(std::string const &_name, std::string const &_title);
		~Warlock(void);
};

#endif
