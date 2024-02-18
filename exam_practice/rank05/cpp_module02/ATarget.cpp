#include"ATarget.hpp"

ATarget::ATarget(std::string const &_type) : type(_type)
{}

ATarget::ATarget(ATarget const &src)
{
	*this = src;
}

ATarget::~ATarget(void)
{}

ATarget &ATarget::operator=(ATarget const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

std::string const &ATarget::getType(void) const
{
	return(this->type);
}

void	ATarget::getHitBySpell(ASpell const &src) const
{
	std::cout << this->type << " has been " << src.getEffects() << "!\n";
}
