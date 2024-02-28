#pragma once

#include "ATarget.hpp" // ? Include header from parent class

class BrickWall : public ATarget {

public:

  BrickWall(void);
  ~BrickWall(void);
  virtual ATarget *clone() const; // ? Mandatory method for cloning as pure is implemented in parent Class

};
