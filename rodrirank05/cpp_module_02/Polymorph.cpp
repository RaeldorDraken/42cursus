#include "Polymorph.hpp"

// ? ATarget constructor is called when Dummy constructor is instantiated passing the arguments stated in the exam subject (name, effects)
Polymorph::Polymorph():ASpell("Polymorph", "turned into a critter") {return ;} 

Polymorph::~Polymorph(){return ;}

ASpell *Polymorph::clone() const
{
  return (new Polymorph()); // ? Mandatory method for cloning as pure is implemented in parent Class
}
