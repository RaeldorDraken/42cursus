## Subject
Create an abstract class called <b> ASpell </b>, in Coplien's form, that has the following protected attributes:
<li> name (string) </li>
<li> effects (string) </li>
<br>
Both will have getters (<i>getName</i> and <i>getEffects</i>) that return strings.<br>
Also add a <i>clone</i> pure method that returns a pointer to <b>ASpell</b>. <br>
All these functions can be called on a constant object. <br>
<b>ASpell</b> has a <i>constructor</i> that takes its name and its effects, in that order. <br>

<br>
Now you will create an <b>ATarget</b> abstract class, in Coplien's form. <br>
It has a type attribute, which is a string, and its associated getter, <i>getType</i>, that return a reference to constant string.<br>
In much the same way as <b>ASpell</b>, it has a <i>clone()</i> pure method.<br>
All these functions can be called on a constant object.<br>
It has a <i>constructor</i> that takes its type.
<br>
<br>
Now, add to your <b>ATarget</b> a <i>getHitBySpell</i> function that takes a reference to constant <b>ASpell</b>. <br>
It will display: <br>

```
<TYPE> has been <EFFECTS>! 
```

<br>
"TYPE" is the <b>ATarget's</b> type, and "EFFECTS" is the return of the <b>ASpell's</b> getEffects function. <br>
Finally, add to your <b> ASpell </b> class a <i>launch</i> function that takes a reference to constant <b>ATarget</b>.<br>
This one will simply call the <i>getHitBySpell</i> of the passed object, passing the current instance as parameter.
<br>
<br>
When all this is done, create an implementation of <b> ASpell </b> called <b> Fwoosh </b> . <br>
Its default <i>constructor</i> will set the name to "Fwoosh" and the effects to "fwooshed".<br>
You will, of course, implement the <i>clone()</i> method.<br>
In the case of <b>Fwoosh</b>, it will return a pointer to a new <b>Fwoosh</b> object.<br>
<br>
In the same way, create a concrete <b> ATarget </b> called <b> Dummy </b>, the type of which is "Target Practice Dummy". <br>
You must also implement its <i>clone()</i> method.<br>

<br>
Add to the Warlock the following member functions:
<li> <i>learnSpell</i>, takes a pointer to <b> ASpell</b>, that makes the Warlock learn a spell. </li>
<li> <i>forgetSpell</i>, takes a string corresponding a to a spell's name, and makes the <b> Warlock </b>forget it. If it's not a known spell, does nothing. </li>
<li> <i>launchSpell</i>, takes a string (a spell name) and a reference to <b>ATarget</b>, that launches the spell on the selected target. If it's not a known spell, does nothing. </li>

You will need a new attribute to store the spells your <b> Warlock knows</b>. <br>
Several types fit the bill, it's up to you to choose the best one.
  
## Main function
```
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
```
  
## Output
```
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, the Titled!$
Target Practice Dummy has been fwooshed!$
Richard: My job here is done!$  
```
