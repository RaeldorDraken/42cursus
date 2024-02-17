#include "SpellBook.hpp"

SpellBook::SpellBook(void) {return ;}

SpellBook::~SpellBook(void) {return ;}

void SpellBook::learnSpell(ASpell *spell)
{
  if (spell)
    {
      std::string my_spell = spell->getName();
      spells.insert(std::pair<std::string, ASpell *>(my_spell, spell->clone()));   
    }

  
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
  std::map<std::string, ASpell *>::iterator it = spells.find(spell_name);

  if (it != spells.end())
    {
      delete it->second;
      spells.erase(spell_name);
    }
}

ASpell *SpellBook::createSpell(std::string const &spell_name)
{
  std::map<std::string, ASpell *>::iterator it = spells.find(spell_name);

  if (it != spells.end())
    return (spells[spell_name]);
  return NULL;    
}
