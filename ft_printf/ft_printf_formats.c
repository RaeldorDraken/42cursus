/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:42:19 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/21 12:23:20 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	get_formatting(t_print *tab, char *string, int position)
{
	while (*ft_strchr("cspdiuxX%", string[position]) == '\0')
	{
		position = first_format(tab, string, position);
		position = second_format(tab, string, position);
	}
	if (string[position] == '%')
		return (position);
	ft_print_tab(tab, string, position);
	return (position);
}

void	ft_print_tab(t_print *tab, char *string, int position)
{
	if (string[position] == 'c')
		ft_tab_char(tab);
	else if (string[position] == 's')
		ft_tab_string(tab);
	else if (string[position] == 'p')
		ft_tab_pointer(tab);
	else if (string[position] == 'd')
		ft_tab_decimal(tab);
	else if (string[position] == 'i')
		ft_tab_integer(tab);
	else if (string[position] == 'u')
		ft_tab_unsigned(tab);
	else if (string[position] == 'x')
		ft_tab_hexmin(tab);
	else if (string[position] == 'X')
		ft_tab_hexmax(tab);
}

int	first_format(t_print *tab, char *string, int position)
{
	if (string[position] == '-')
	{
		tab->score = 1;
		position ++;
	}
	else if (string[position] == '0')
	{
		tab->nopad = 1;
		position ++;
	}
	else if (string[position] == '.')
	{
		tab->fstop = 1;
		position ++;
	}
	else if (string[position] >= '1' && string[position] <= '9')
	{
		tab->width = (tab->width * 10) + string[position];
		position ++;
	}
	return (position);
}

int	second_format(t_print *tab, char *string, int position)
{
	if (string[position] == '#')
	{
		tab->precise = 1;
		position ++;
	}
	else if (string[position] == ' ')
	{
		tab->space = 1;
		position ++;
	}
	else if (string[position] == '+')
	{
		tab->sign = 1;
		position ++;
	}
	return (position);
}
