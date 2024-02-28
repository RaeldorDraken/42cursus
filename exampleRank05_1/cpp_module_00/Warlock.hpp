#pragma once // ? You can skip ifndef and define lines using the shorthand #pragma once

#include <iostream> // ? Always include your needed libraries in your classes snce they need to work in a stand alone model. iostream is needed for all std oprations

class Warlock {

public:

  // ? Only the following constructor will be called. This is staed in the exam subject
  Warlock(std::string const &name, std::string const &title);
  ~Warlock(void); // ? Destructor always public!!!

  std::string const &getName(void) const; // ? this is tricky since you both have to reference both strings as const and also the result of the operation will not modify them 
  std::string const &getTitle(void) const;

  void setTitle(std::string const &title); // ? set title also takes a reference to a constant string

  void introduce() const; // ? This function only states that no modification is made in the function

  

private:

  Warlock(void); // ? Default constructor wih no params will neves be called
  Warlock(const Warlock &inst); // ? Copy constructor will never be called either.
  Warlock &operator=(const Warlock &inst); // ? No Warlock will be used in any = operation against another Warlock in this exercice


  // ? Our private vars only accesible via our getters and setter
  std::string name;
  std::string title;

};

