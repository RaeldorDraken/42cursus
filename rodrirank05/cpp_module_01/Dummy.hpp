#pragma once

#include "ATarget.hpp" // ? Include header from parent class

class Dummy : public ATarget {

public:

  Dummy(void);
  ~Dummy(void);
  virtual ATarget *clone() const; // ? Mandatory method for cloning as pure is implemented in parent Class

};
