#include "Fireball.hpp"

// ? ATarget constructor is called when Dummy constructor is instantiated passing the arguments stated in the exam subject (name, effects)
Fireball::Fireball():ASpell("Fireball", "burnt to a crisp") {return ;} 

Fireball::~Fireball(){return ;}

ASpell *Fireball::clone() const
{
  return (new Fireball()); // ? Mandatory method for cloning as pure is implemented in parent Class
}
