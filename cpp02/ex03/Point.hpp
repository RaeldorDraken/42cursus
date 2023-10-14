/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:28 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/14 18:31:40 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point &src);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		~Point();
		
		Point &operator=(const Point &rhs);

		void	setX(const float x);
		void	setY(const float y);
		float	getX() const;
		float	getY() const;
		Fixed	getFixedX() const;
		Fixed	getFixedY() const;

	private:
		Fixed const _x;
		Fixed const _y;
}	;

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif