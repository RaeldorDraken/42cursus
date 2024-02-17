#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook {

public:

  SpellBook(void);
  ~SpellBook(void);

  void learnSpell(ASpell *spell);
  void forgetSpell(std::string const &spell_name);
  ASpell *createSpell(std::string const &spell_name);

private:

  SpellBook(SpellBook const &inst);
  SpellBook &operator=(SpellBook const &inst);

  std::map<std::string, ASpell *> spells;

};
