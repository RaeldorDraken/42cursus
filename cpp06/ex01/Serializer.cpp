/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:15:02 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/26 17:15:45 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
	return ;
}

Serializer::~Serializer(void)
{
	return ;
}

Serializer	&Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}
