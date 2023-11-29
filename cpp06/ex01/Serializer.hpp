/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:14:15 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/29 19:13:49 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

typedef struct s_Data
{
	char		c;
	int			n;
	int			*p;
}	Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);

		Serializer	&operator=(Serializer const &rhs);
};

#endif