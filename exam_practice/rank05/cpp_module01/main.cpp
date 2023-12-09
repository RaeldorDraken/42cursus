#include"ASpell.cpp"
#include"ATarget.cpp"

int	main()
{
	spell = new ASpell("ice", "chills");
	target = new ATarget("dummy");

	spell.launch(target);

	return 0;
}
