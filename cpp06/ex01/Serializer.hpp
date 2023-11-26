/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:14:15 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/26 17:15:29 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <iomanip>
# include <cmath>

class Serializer
{
	public:

	private:
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);

		Serializer	&operator=(Serializer const &rhs);
};

#endif