#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include<iostream>
#include<map>
#include"ASpell.hpp"
#include"ATarget.hpp"
#include"SpellBook.hpp"

class Warlock
{
	public:
		Warlock(std::string const &_name, std::string const &_title);
		~Warlock(void);
		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void	setTitle(std::string const &_title);
		void	introduce(void) const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string _name);
		void	launchSpell(std::string _name, ATarget const &target);
	private:
		std::string name;
		std::string title;
		SpellBook	spellBook;
};

#endif
