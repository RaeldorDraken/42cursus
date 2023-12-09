#include"ATarget.hpp"

ATarget::ATarget(std::string _type) : type(_type)
{}

ATarget::~ATarget()
{}

std::string const &ATarget::getType() const
{
	return(this->type);
}

ATarget	*ATarget::clone()
{
	return(this);
}

std::string const	ASpell::getName()
{
	return(this->name);
}

void	ATarget::getHitBySpell(ASpell &src)
{
	std::cout << this->type << " has been " << src.getEffects() << "!\n";
}
