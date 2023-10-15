/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:40 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/15 12:36:55 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool b1, b2, b3;

	b1 = ((point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX())) < 0.0f;
	b2 = ((point.getX() - b.getX()) * (c.getY() - b.getY()) - (point.getY() - b.getY()) * (c.getX() - b.getX())) < 0.0f;
	b3 = ((point.getX() - c.getX()) * (a.getY() - c.getY()) - (point.getY() - c.getY()) * (a.getX() - c.getX())) < 0.0f;

	if ((b1 == b2) && (b2 == b3))
		return (true);
	return (false);
}