#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {

public:
  TargetGenerator(void);
  ~TargetGenerator(void);

  void learnTargetType(ATarget *target);
  void forgetTargetType(std::string const &target_type);
  ATarget *createTarget(std::string const &target_type);


private:

  TargetGenerator(TargetGenerator const &inst);
  TargetGenerator &operator=(TargetGenerator const &inst);

  std::map<std::string, ATarget *> targets;
};
