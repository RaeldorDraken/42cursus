#include<iostream>

class Warlock
{
	private:
		std::string	name;
		std::string	title;
	public:
		std::string	const &getName() const;
		std::string	const &getTitle() const;
		void	setTitle(std::string const &_title);
		void	introduce() const;
		Warlock(std::string const &_name, std::string const &_title);
		~Warlock();
} ;
