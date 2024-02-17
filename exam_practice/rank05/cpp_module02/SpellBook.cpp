#include"SpellBook.hpp"

SpellBook::SpellBook(void) : list()
{}

SpellBook::~SpellBook(void)
{}

void	SpellBook::learnSpell(ASpell *spell)
{
	this->list[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(const std::string &_name)
{
	if (this->list.find(_name) != this->list.end())
		delete this->list[_name];
	this->list.erase(_name);
}

ASpell *SpellBook::createSpell(const std::string &_name)
{
	if (this->list.find(_name) != this->list.end())
		return (this->list[_name]);
	return (NULL);
}
