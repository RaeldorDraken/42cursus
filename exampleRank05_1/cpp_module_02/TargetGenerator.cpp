#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {return ;}

TargetGenerator::~TargetGenerator(void)
{

  std::map<std::string, ATarget *>::iterator it;
  std::map<std::string, ATarget *>::iterator it_end = targets.end();

  for (it = targets.begin(); it != it_end; it++)
    delete it->second;
  targets.clear();
  
}

void TargetGenerator::learnTargetType(ATarget *target)
{
  if (target)
    {
      std::string my_target = target->getType();
      targets.insert(std::pair<std::string, ATarget *>(my_target, target->clone()));
    }
}

void TargetGenerator::forgetTargetType(std::string const &target_type)
{
  std::map<std::string, ATarget *>::iterator it = targets.find(target_type);

  if (it != targets.end())
    {
      delete it->second;
            targets.erase(target_type);
    }
}

ATarget *TargetGenerator::createTarget(std::string const &target_type)
{
  std::map<std::string, ATarget *>::iterator it = targets.find(target_type);

  if (it != targets.end())
    return (targets[target_type]);
  return (NULL);
}



