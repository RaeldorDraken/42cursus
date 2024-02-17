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

