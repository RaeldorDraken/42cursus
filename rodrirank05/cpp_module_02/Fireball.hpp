#pragma once

#include "ASpell.hpp" // ? Include header from parent class

class Fireball : public ASpell {

public:

  Fireball(void);
  ~Fireball(void);
  virtual ASpell *clone() const; // ? Mandatory method implemented as pure in parent class

};
