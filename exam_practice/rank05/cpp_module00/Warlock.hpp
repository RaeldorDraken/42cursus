#include<iostream>

class Warlock
{
	public:
		Warlock(std::string const &_name, std::string const &_title);
		~Warlock(void);
		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void	setTitle(std::string const &_title);
		void	introduce(void) const;
	private:
		std::string	name;
		std::string	title;
};
