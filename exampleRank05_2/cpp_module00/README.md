## Subject
Make a Warlock class. It has to be in Coplien's form.

It has the following private attributes:
<li> name (string) </li>
<li> title (string)</li>
 <br>
Since they're private, you will write the following getters:
<li> getName, returns a reference to constant string </li>
<li> getTitle, returns a reference to constant string </li> 
Both these functions will have to be callable on a constant Warlock.
<br>
<br>
Create the following setter:
<li> setTitle, returns void and takes a reference to constant string </li> 
 <br>
Your Warlock will also have, in addition to whatever's required by Coplien's form, a constructor that takes, in this order, its name and title.

Your Warlock will not be able to be copied, instantiated by copy, or instantiated without a name and a title.

## Main function
```
int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
```

## Output
```
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Mistress of Magma!$
Richard - Mistress of Magma$
Jack: This looks like another boring day.$
Jack: I am Jack, the Long!$
Jack: I am Jack, the Mighty!$
Jack: My job here is done!$
Richard: My job here is done!$
~$
```
