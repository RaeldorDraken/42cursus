#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}


void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

std::string levels[] = {"debug", "info", "warning", "error"};

static void	lowercased(std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void	Harl::complain(std::string level)
{
	void (Harl::*func_ptr)(void);
	lowercased(level);
	int	lvl = -1;
	for(int i = -1; i < 4; i ++)
	{
		if (level == levels[i])
			lvl = i;
	}
	switch (lvl)
	{
		case DEBUG:
			func_ptr = &Harl::debug;
			(this->*func_ptr)();
		case INFO:
			func_ptr = &Harl::info;
			(this->*func_ptr)();
		case WARNING:
			func_ptr = &Harl::warning;
			(this->*func_ptr)();
		case ERROR:
			func_ptr = &Harl::error;
			(this->*func_ptr)();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return;
	}
}
