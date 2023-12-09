#include"ASpell.hpp"

ASpell::ASpell(std::string _name, std::string _effect) : name(_name), effects(_effect)
{
	
}

ASpell::~ASpell()
{}

std::string const	ASpell::getName()
{
	return(this->name);
}

std::string const	ASpell::getEffects()
{
	return(this->effects);
}

ASpell	*ASpell::clone()
{
	return(this);
}

void	ASpell::launch(ATarget const &tango) const
{
	tango.getHitBySpell(*this);	
}
