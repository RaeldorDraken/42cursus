#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects)
{
}

ASpell::ASpell()
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(ASpell const &copy)
{
	*this = copy;
}

ASpell &ASpell::operator=(ASpell const &copy)
{
	this->name = copy.name;
	this->effects = copy.effects;

	return (*this);
}

std::string ASpell::getName() const
{
	return (this->name);
}

std::string ASpell::getEffects() const
{
	return (this->effects);
}

void	ASpell::launch(ATarget const &target)
{
	target.getHitBySpell(*this);
}
