#include "Warlock.hpp"

// ! Important DOUBLE CHECK your string returns. Order and position of ", " and "!" are VERY important. 

// ? Short hand constructor assigning values to private vars as object is instantiated
Warlock::Warlock(std::string const &name, std::string const &title) :
  name (name),
  title (title)
{
  

  std::cout << this->name << ": This looks like another boring day." << std::endl;
  return ;
}

Warlock::~Warlock(void)
{
  std::cout << this->name << ": My job here is done!" << std::endl;  

  return ;
}

std::string const &Warlock::getName() const
{
  return (this->name);
}

std::string const &Warlock::getTitle() const
{
  return (this->title);
}

void Warlock::setTitle(std::string const &title)
{
  this->title = title;
}

void Warlock::introduce() const
{
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
  spells.learnSpell(spell); // This is abstracted now in the SpellBook class
}

void Warlock::forgetSpell(std::string spell_name)
{
  spells.forgetSpell(spell_name); // This is abstracted now in the SpellBook class
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target)
{

  ATarget const *my_target = 0; // ?  NULL

    if (&target == my_target)
      return ; // ? If our target is equal to null do nothing

  ASpell *spell = spells.createSpell(spell_name);

  if (spell) // ? This returns null from SpellBook if not found already in the Spells book
    spell->launch(target);

  
}
