#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}


void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
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
			break;
		case INFO:
			func_ptr = &Harl::info;
			break;
		case WARNING:
			func_ptr = &Harl::warning;
			break;
		case ERROR:
			func_ptr = &Harl::error;
			break;
		default:
			std::cout << "Invalid level passed to complain function." << std::endl;
			return;
	}
	(this->*func_ptr)();
}
