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

  // ! To avoid leaks we need to remove every learn spell upon destruction of ou Warlock

  std::map<std::string, ASpell *>::iterator it; // ? Set iterator
  std::map<std::string, ASpell *>::iterator it_end = spells.end(); // ? set end of iterator

  for (it = spells.begin(); it != it_end; it++)
    delete (it->second); // ? Here we delete the pointers to the ASpell learned spell. second is just the second place of the associatibe array maps create.

  spells.clear(); // ? here we delete the actual map once all pointers have been deleted  

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
  std::string spell_to_find = spell->getName(); // ? look for the spell to add by its name from the member function implemented in the passed onject. Use -> since it is a pointer

  if (spell && spells.find(spell_to_find) == spells.end()) // ? If spell is not null and we CANNOT find the spell already in the list of spells from the map
    spells.insert(std::pair<std::string, ASpell *>(spell_to_find, spell->clone())); // ? Here we insert into our map for spells the new spell by declaring the format of the new pair and inserting our desired values. the string is the spell we were lokking for and did not find, and the actual reference to the spell is a pointer to a clone of the spell already implemented in each spell with inheratance from ASpell)

  
    
}

void Warlock::forgetSpell(std::string spell_name)
{
  // ? Here we set our iterator based on the ocurrence in our spells by name. This iterator will have th eposition in which it is found OR will be equal to the end of the map length (spells.end())

  std::map<std::string, ASpell *>::iterator it = spells.find(spell_name); 

  if (it != spells.end())
    {
      delete it->second; // ? Free the pointer to the found spell by using the "second" keyword associate dwith pairing for maps
      spells.erase(spell_name); // ? Here we delete the string asspciated with the spell. For some reason this is automatic???
    }
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target)
{

  ASpell *spell = spells[spell_name]; // TODO For some reason we do not need to use iterators to find the spells we are loking for?. Seems we can access it directly by setting the spell_name we are looking for. I assume is beacuse we reached a point where only ONE spell with that name can be found inside the container

  if (spell)
    spell->launch(target);
}
