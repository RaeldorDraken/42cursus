#include "BrickWall.hpp"

// ? ATarget constructor is called when BrickWall constructor is instantiated passing the argument stated in the exam subject (type)
BrickWall::BrickWall():ATarget("Inconspicuous Red-brick Wall") {return ;} 

BrickWall::~BrickWall(){return ;}

ATarget *BrickWall::clone() const
{
  return (new BrickWall()); // ? Mandatory method for cloning as pure is implemented in parent Class
}
