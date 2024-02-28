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
	std::vector<ASpell *>::iterator iter = vect.begin();

	if (spell)
	{
		for(; iter != vect.end(); iter++)
		{
			if ((*iter)->getName() == spell->getName())
				return ;
		}
		vect.push_back(spell->clone());
	}
}
	
void	Warlock::forgetSpell(std::string spellname)
{
	std::vector<ASpell *>::iterator iter = vect.begin();

	for (; iter != vect.end(); iter++)
	{
		if ((*iter)->getName() == spellname)
		{
			delete *iter;
			vect.erase(iter);
			return ;
		}
	}
}

void	Warlock::launchSpell(std::string spellname, ATarget const &target)
{
	std::vector<ASpell *>::iterator iter = vect.begin();

	for (; iter != vect.end(); iter++)
	{
		if ((*iter)->getName() == spellname)
		{
			(*iter)->launch(target);
		}
	}
}
