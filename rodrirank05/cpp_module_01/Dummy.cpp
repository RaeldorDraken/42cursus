#include "Dummy.hpp"

// ? ATarget constructor is called when Dummy constructor is instantiated passing the argument stated in the exam subject (type)
Dummy::Dummy():ATarget("Target Practice Dummy") {return ;} 

Dummy::~Dummy(){return ;}

ATarget *Dummy::clone() const
{
  return (new Dummy()); // ? Mandatory method for cloning as pure is implemented in parent Class
}
