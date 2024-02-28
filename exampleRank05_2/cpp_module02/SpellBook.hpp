#pragma once
#include <iostream>
#include <vector>
#include "ASpell.hpp"

class ASpell;

class SpellBook
{
	private:
		std::vector<ASpell *> vect;
		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &copy);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &str);
		ASpell* createSpell(std::string const &str);
};
