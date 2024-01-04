#include"SpellBook.hpp"

SpellBook::SpellBook(void) : _spells()
{}

SpellBook::SpellBook(const SpellBook &src)
{
	(void)src;
}

SpellBook	&SpellBook::operator=(const SpellBook &src)
{
	(void) src;
	return (*this);
}

SpellBook::~SpellBook(void)
{
	std::map<std::string, ASpell *>::iterator it;
	for (it = this->_spells.begin(); it != this->_spells.end(); ++it)
		delete it->second;
}

void	SpellBook::learnSpell(ASpell *spell)
{
	this->_spells[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(const std::string &spellName)
{
	if (this->_spells.find(spellName) != this->_spells.end())
		delete this->_spells[spellName];
	this->_spells.erase(spellName);
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
	if (this->_spells.find(spellName) != this->_spells.end())
		return (this->_spells[spellName]);
	return (NULL);
}
