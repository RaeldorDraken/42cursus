/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:48:39 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/09 17:36:40 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int						is_space(char c);

static int						is_sign(char c);

static int						set_len(char *c_num);

static unsigned long long int	make_num(char *c_num, int len);

int	ft_atoi(const char *str)
{
	long int	num;
	char		*c_num;
	int			len;

	num = 0;
	while (is_space(str[0]))
		str++;
	if (!ft_isdigit(str[0]) && !is_sign(str[0]))
		return (0);
	c_num = (char *)str;
	if (is_sign(c_num[0]))
		c_num++;
	if (!ft_isdigit(c_num[0]))
		return (0);
	len = set_len(c_num);
	num = make_num(c_num, len);
	if (str[0] == '-')
		num *= -1;
	return ((int)num);
}

static int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	set_len(char *c_num)
{
	int	i;

	i = 0;
	while (c_num[i])
	{
		if (!ft_isdigit(c_num[i]))
			break ;
		i++;
	}
	i--;
	return (i);
}

static unsigned long long int	make_num(char *c_num, int len)
{
	int							pot;
	unsigned long long int		res;

	res = 0;
	pot = 1;
	while (len >= 0)
	{
		res += (c_num[len] - '0') * pot;
		pot *= 10;
		len--;
	}
	return (res);
}
