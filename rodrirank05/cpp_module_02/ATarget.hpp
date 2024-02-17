#pragma once

#include <iostream>

class ASpell; // ? include Abstract class Spell since we are using it in getHitBySpell method

class ATarget {

public:

  ATarget(void);
  ATarget(std::string const &type);
  ATarget(const ATarget &inst);
  ATarget &operator=(const ATarget &inst);
  virtual ~ATarget(void);

  virtual ATarget *clone() const = 0;

  std::string const &getType() const;

  void getHitBySpell(ASpell const &spell) const; // ? This is the function that will be called inderectly by Warlock when calling launch method from any ASpell children class

protected:

  std::string type;


};

#include "ASpell.hpp" // ? Also include header for Abstract class Spell
