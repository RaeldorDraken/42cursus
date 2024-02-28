#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		std::vector<ASpell *>::iterator iter = vect.begin();
		for (; iter != vect.end(); iter++)
		{
			if ((*iter)->getName() == spell->getName())
				return ;
		}
		vect.push_back(spell->clone());
	}
}

void	SpellBook::forgetSpell(std::string const &str)
{
	std::vector<ASpell *>::iterator iter = vect.begin();
	for (; iter != vect.end(); iter++)
	{
		if ((*iter)->getName() == str)
		{
			delete *iter;
			this->vect.erase(iter);
			return ;
		}
	}
}

ASpell	*SpellBook::createSpell(std::string const &str)
{
	std::vector<ASpell *>::iterator iter = vect.begin();
	for (; iter != vect.end(); iter++)
	{
		if ((*iter)->getName() == str)
		{
			return (*iter);
		}
	}
	return (NULL);
}
