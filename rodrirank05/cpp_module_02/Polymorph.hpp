#pragma once

#include "ASpell.hpp" // ? Include header from parent class

class Polymorph : public ASpell {

public:

  Polymorph(void);
  ~Polymorph(void);
  virtual ASpell *clone() const; // ? Mandatory method implemented as pure in parent class

};
