/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:19:59 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/05 18:00:43 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{ 
	return;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	return;
}

RPN::~RPN(void)
{
	return;
}

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return *this;
}

int		RPN::calculate(char op)
{
	int	a = _stack.top();
	_stack.pop();
	int	b = _stack.top();
	_stack.pop();
	
	int	i = 0;
	char sign[4] = {'-','+','*','/'};

	while (sign[i] != op)
		i++;
	switch(i)
	{
		default: {
			throw std::invalid_argument("Invalid operator!"); }
		case 0: {
			return (b - a); }
		case 1: {
			return (b + a); }
		case 2: {
			double safe = (static_cast<double>(b) * static_cast<double>(a));
			if (safe > INT_MAX || safe < INT_MIN)
			{
				std::cout << "Result number is too big or too small!" << std::endl;
				throw std::invalid_argument("Result number is too big or too small!");
			}
			return (b * a); }
		case 3: {
			if (a == 0)
				throw std::invalid_argument("Dividing by 0 not allowed!");
			return (b / a); }
	}
	return (0);
}

void	RPN::parsing(std::string const &str)
{
	std::istringstream	iss(str);
	std::string			tmp;
	int					nb;

	while (iss >> tmp)
	{
		if (tmp.length() == 1 && !isdigit(tmp[0]))
		{
			if (_stack.size() < 2)
			{
				throw std::exception();
			}
			_stack.push(calculate(tmp[0]));
		}
		else
		{
			nb = atoi(tmp.c_str());
			_stack.push(nb);
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error: Unexpected operation 2" << std::endl;
		throw std::exception();
	}
}

int		RPN::rpn(std::string const &str)
{
	try
	{
		parsing(str);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: Input not properly formatted" << std::endl;
		return (0);
	}
	try
	{
		std::cout << _stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: Unexpected operation" << std::endl;
		return (0);
	}
	return (1);
}

std::stack<int>	RPN::_stack;