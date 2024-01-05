#include"Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title) : name(_name), title(_title)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job here is done!\n";
}

std::string const	&Warlock::getName(void) const
{
	return(this->name);
}

std::string const	&Warlock::getTitle(void) const
{
	return(this->title);
}

void	Warlock::setTitle(std::string const &_title)
{
	this->title = _title;
}

void	Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		this->spellList[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(std::string spellName)
{
	if (this->spellList.find(spellName) != this->spellList.end())
	{
		delete this->spellList.find(spellName)->second;
		this->spellList.erase(this->spellList.find(spellName));
	}
}

void	Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	if (this->spellList.find(spellName) != this->spellList.end())
		this->spellList.find(spellName)->second->launch(target);
}
