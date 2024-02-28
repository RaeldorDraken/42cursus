#include "ATarget.hpp"

ATarget::ATarget(std::string const &attribute): attribute(attribute)
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(ATarget const &copy)
{
	*this = copy;
}

ATarget &ATarget::operator=(ATarget const &copy)
{
	this->attribute = copy.attribute;

	return (*this);
}

std::string ATarget::getType() const
{
	return (this->attribute);
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << attribute << " has been " << spell.getEffects() << "!\n";
}
