#pragma once
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class ATarget;
class Warlock
{
	private:
		std::vector<ASpell *> vect;
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &copy);

	public:
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
