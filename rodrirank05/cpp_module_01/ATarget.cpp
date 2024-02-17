#include "ATarget.hpp"

ATarget::ATarget(void){return ;} // ? Default constructor. Due to cannonical it is mandatory

ATarget::ATarget(std::string const &type) :
  type (type)
{
  return ;
} // ? Constructor with params. This is the one we will be using

ATarget::ATarget(const ATarget &inst)
{
  *this = inst;
} // ? Copy constructor

ATarget &ATarget::operator=(ATarget const &inst)
{
  this->type = inst.type;
  return (*this);
} // ? = operator assigment. We need to copy ALL protected vars 

ATarget::~ATarget(void){return ;}

std::string const &ATarget::getType() const
{
  return (this->type);
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
  std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
} // ? this function will be inderectly called by ASpell launch method

