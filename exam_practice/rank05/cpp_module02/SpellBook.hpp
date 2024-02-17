#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include<iostream>
#include<map>
#include"ASpell.hpp"

class SpellBook
{
	public:
		SpellBook(void);
		~SpellBook(void);

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &_name);
		ASpell	*createSpell(std::string const &_name);
	private:
		std::map<std::string, ASpell*> list;
};

#endif
