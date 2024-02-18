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
		this->list[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(std::string _name)
{
	if (this->list.find(_name) != this->list.end())
	{
		delete this->list[_name];
		this->list.erase(this->list.find(_name));
	}
}

void	Warlock::launchSpell(std::string _name, ATarget const &target)
{
	if (this->list.find(_name) != this->list.end())
		this->list.find(_name)->second->launch(target);
}
