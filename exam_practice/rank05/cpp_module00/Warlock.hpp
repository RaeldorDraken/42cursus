#include<iostream>

class Warlock
{
	private:
		std::string	name;
		std::string	title;
	public:
		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void	setTitle(std::string const &_title);
		void	introduce(void) const;
		Warlock(std::string const &_name, std::string const &_title);
		~Warlock(void);
};
