#include "ASpell.hpp"

ASpell::ASpell(void){return ;} // ? Default constructor. Due to cannonical it is mandatory

ASpell::ASpell(std::string const &name, std::string const &effects) :
  name (name),
  effects (effects)
{
  return ;
} // ? Constructor with params. This is the one we will be using

ASpell::ASpell(const ASpell &inst)
{
  *this = inst;
} // ? Copy constructor

ASpell &ASpell::operator=(ASpell const &inst)
{
  this->name = inst.name;
  this->effects = inst.effects;
  return (*this);
} // ? = operator assigment. We need to copy ALL protected vars 

ASpell::~ASpell(void){return ;}

std::string const &ASpell::getName() const
{
  return (this->name);
}

std::string const &ASpell::getEffects() const
{
  return (this->effects);
}

void ASpell::launch(ATarget const &target) const
{
  target.getHitBySpell((*this)); // ? we are accesing target by . due to being a reference form &
}

