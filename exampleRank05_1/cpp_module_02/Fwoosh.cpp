#include "Fwoosh.hpp"

// ? ATarget constructor is called when Dummy constructor is instantiated passing the arguments stated in the exam subject (name, effects)
Fwoosh::Fwoosh():ASpell("Fwoosh", "fwooshed") {return ;} 

Fwoosh::~Fwoosh(){return ;}

ASpell *Fwoosh::clone() const
{
  return (new Fwoosh()); // ? Mandatory method for cloning as pure is implemented in parent Class
}
