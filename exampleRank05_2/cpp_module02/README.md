## Subject
Create the following two spells, on the same model as <b>Fwoosh</b>:
<li> <b>Fireball</b> (Name: "Fireball", Effects: "burnt to a crisp") </li>
<li> <b>Polymorph</b> (Name: "Polymorph", Effects: "turned into a critter") </li>
<br>
In addition to this, just so he won't have only dummy to attack, let's make a new target for him, which will be the <b>BrickWall</b> (Type: "Inconspicuous Red-brick Wall"). <br>
<br>
Now, make a <b>SpellBook</b> class, in canonical form, that can't be copied or instantiated by copy.<br>It will have the following functions:
<li> void learnSpell(ASpell*), that COPIES a spell in the book. </li>
<li> void forgetSpell(string const &), that deletes a spell from the book, except if it isn't there. </li>
<li> ASpell* createSpell(string const &), that receives a string corresponding to the name of a spell, creates it, and returns it. </li>
<br>
Modify the <b>Warlock</b>, now, make it have a spell book that will be created with him and destroyed with him. Also make his learnSpell and forgetSpell functions call those of the spell book.
<br><br>
The launchSpell function will have to use the <b>SpellBook</b> to create the spell it's attempting to launch.
<br><br>
Make a <b>TargetGenerator</b> class, in canonical form, and as before, non-copyable.
<br>
It will have the following functions:
<li> void learnTargetType(ATarget*), teaches a target to the generator. </li>
<li> void forgetTargetType(string const &), that makes the generator forget a target type if it's known. </li>
<li> ATarget* createTarget(string const &), that creates a target of the specified type. </li>

## Main
```
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
```

## Output
```
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Hello, I'm Richard the Warlock!!$
Inconspicuous Red-brick Wall has been turned into a critter!$
Inconspicuous Red-brick Wall has been burnt to a crisp!$
Richard: My job here is done!$
~$
```
