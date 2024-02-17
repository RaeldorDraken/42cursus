#pragma once

#include "ASpell.hpp" // ? Include header from parent class

class Fwoosh : public ASpell {

public:

  Fwoosh(void);
  ~Fwoosh(void);
  virtual ASpell *clone() const; // ? Mandatory method implemented as pure in parent class

};
