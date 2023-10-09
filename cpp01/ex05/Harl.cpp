#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: This is a debug message." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: This is an info message." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: This is a warning message." << std::endl;
}


void	Harl::error(void)
{
	std::cout << "ERROR: This is an error message." << std::endl;
}


void	Harl::complain(std::string level)
{
	void (Harl::*func_ptr)(void);
	if (level == "debug") {
		func_ptr = &Harl::debug;
	} else if (level == "info") {
		func_ptr = &Harl::info;
	} else if (level == "warning") {
		func_ptr = &Harl::warning;
	} else if (level == "error") {
		func_ptr = &Harl::error;
	} else {
		std::cout << "Invalid level passed to complain function." << std::endl;
		return;
	}
	(this->*func_ptr)();
}
