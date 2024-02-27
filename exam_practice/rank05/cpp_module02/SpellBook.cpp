#include"SpellBook.hpp"

SpellBook::SpellBook(void) : list()
{}

SpellBook::~SpellBook(void)
{
	std::map<std::string, ASpell *>::iterator it;
	std::map<std::string, ASpell *>::iterator it_end = list.end();

	for (it = list.begin(); it != it_end; it++)
		delete it->second;
	list.clear();
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
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
