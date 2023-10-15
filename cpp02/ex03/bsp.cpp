/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:40 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/15 17:39:21 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool b1, b2, b3;

	Fixed px = point.getX();
    Fixed py = point.getY();
    Fixed ax = a.getX();
    Fixed ay = a.getY();
    Fixed bx = b.getX();
    Fixed by = b.getY();
    Fixed cx = c.getX();
    Fixed cy = c.getY();

	b1 = ((px - ax) * (by - ay) - (bx - ax) * (py - ay)) < 0;
	b2 = ((px - bx) * (cy - by) - (cx - bx) * (py - by)) < 0;
	b3 = ((px - cx) * (ay - cy) - (ax - cx) * (py - cy)) < 0;	

	return ((b1 == b2) && (b2 == b3));
}