/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:20:02 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/21 11:13:22 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <climits>

class RPN
{
	public:
		static int	rpn(std::string const &str);
	private:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);
		RPN &operator=(RPN const &rhs);

		static int		calculate(char op);
		static void		parsing(std::string const &str);

		static std::stack<int>	_stack;
} ;

#endif