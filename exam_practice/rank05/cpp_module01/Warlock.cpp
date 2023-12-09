#include"Warlock.hpp"

Warlock::Warlock(std::string const &_name, std::string const &_title) : name(_name), title(_title)
{
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!\n";	
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}

std::string const &Warlock::getName() const
{
	return(this->name);
}

std::string const &Warlock::getTitle() const
{
	return(this->title);
}

void	Warlock::setTitle(std::string const &_title)
{
	this->title = _title;
}
