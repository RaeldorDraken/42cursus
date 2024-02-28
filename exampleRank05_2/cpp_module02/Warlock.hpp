#pragma once
#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);

	public:
		SpellBook spbook;
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void	setTitle(std::string const &str);
		void	introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellname);
		void	launchSpell(std::string spellname, ATarget const &target);
};
