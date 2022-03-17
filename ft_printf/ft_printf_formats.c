/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:42:19 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/17 11:13:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

typedef struct s_printf
{
	va_list	args;
	int		width;
	int		precise;
	int		nopad;
	int		fstop;
	int		score;
	int		len;
	int		sign;
	int		zero;
	int		precent;
	int		space;
}	t_printf;

int	format_percent(void)
{
	ft_putstr("%");
	return (1);
}
