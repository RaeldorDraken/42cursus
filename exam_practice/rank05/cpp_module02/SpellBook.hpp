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
		void	forgetSpell(std::string const &spellName);
		ASpell	*createSpell(const std::string &spellName);
	private:
		std::map<std::string, ASpell *> _spells;
};

#endif
