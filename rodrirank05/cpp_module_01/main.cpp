// ? This code is provided by the EXAM make sure your output is EXACTLY like this. Use | cat -e to get show your breaklines:

// * Richard: This looks like another boring day.$
// * Richard: I am Richard, the Titled!$
// * Target Practice Dummy has been fwooshed!$
// * Richard: My job here is done!$


#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
