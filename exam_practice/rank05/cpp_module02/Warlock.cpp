#include"Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title) : name(_name), title(_title)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job here is done!\n";
}

std::string const &Warlock::getName(void) const
{
	return(this->name);
}


std::string const &Warlock::getTitle(void) const
{
	return(this->title);
}

void Warlock::setTitle(std::string const &_title)
{
	this->title = _title;
}

void Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
	this->_spell.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	this->_spell.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	ASpell *temp = this->_spell.createSpell(spellName);
	if (temp != NULL)
		temp->launch(target);
}
