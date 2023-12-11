#include"ASpell.hpp"

ASpell::ASpell(std::string const _name, std::string const _effects) : name(_name), effects(_effects)
{

}

ASpell::ASpell(ASpell const &src)
{
	*this = src;
}

ASpell::~ASpell(void) {}

std::string const	ASpell::getName(void) const
{
	return(this->name);
}

std::string const	ASpell::getEffects(void) const
{
	return(this->effects);
}

void	ASpell::launch(ATarget const &tango) const
{
	tango.getHitBySpell(*this);
}

ASpell &ASpell::operator=(ASpell const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getName();
		this->effects = rhs.getEffects();
	}
	return (*this);
}
