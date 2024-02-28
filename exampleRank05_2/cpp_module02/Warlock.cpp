#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): name(name), title(title)
{
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!\n";
}

Warlock::Warlock(Warlock const &copy)
{
	*this = copy;
}

Warlock &Warlock::operator=(Warlock const &copy)
{
	this->name = copy.name;
	this->title = copy.title;

	return (*this);
}

std::string const &Warlock::getName() const
{
	return (this->name);
}
std::string const &Warlock::getTitle() const
{
	return (this->title);
}

void	Warlock::setTitle(std::string const &str)
{
	this->title = str;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void	Warlock::learnSpell(ASpell *spell)
{
	this->spbook.learnSpell(spell);
}
	
void	Warlock::forgetSpell(std::string spellname)
{
	this->spbook.forgetSpell(spellname);
}

void	Warlock::launchSpell(std::string spellname, ATarget const &target)
{
	ASpell *temp = spbook.createSpell(spellname);
	if (temp)
		temp->launch(target);
}
