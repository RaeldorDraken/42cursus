#pragma once

#include <iostream>

class ATarget; // ? include Abstract class Target since we are using it in launch method

class ASpell {

public:

  // ? Cannonical 
  ASpell(void);
  ASpell(std::string const &name, std::string const &effects);
  ASpell(const ASpell &inst);
  ASpell &operator=(const ASpell &inst);
  virtual ~ASpell(void); // ? Desctructors are mandatory to be virtual and implemented in any child class with inheratance to this Abstract class.

  // ? This pure method is forced to be implemented in any classes with inheratance from this Asbtract class a
  virtual ASpell *clone() const = 0; 

  std::string const &getName() const;
  std::string const &getEffects() const;

  void launch(ATarget const &target) const; // ? This is the method that will be called indirectly from Warlock

protected: 

  // ? The protected vars will be only accesible from classes that inherting from this Abstract class.The are private ut extended to childs
  std::string name;
  std::string effects;

};

#include "ATarget.hpp" // ? include Abstract class Target header as well 
