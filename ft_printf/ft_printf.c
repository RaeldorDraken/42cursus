/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:43:08 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/17 12:30:43 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

t_printf	*initialize_tab(t_printf *tab)
{
	tab->width = 0;
	tab->precise = 0;
	tab->nopad = 0;
	tab->fstop = 0;
	tab->score = 0;
	tab->len = 0;
	tab->sign = 0;
	tab->zero = 0;
	tab->percent = 0;
	tab->space = 0;
	return (tab);
}

int	get_formatting(t_print tab, char *string, int position)
{
	while (ft_strchr("udcsupxX%", string[position]) == '\0')
	{
		if(string[position] == '-')
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
			tab->width = (tab->width *10) + string[position];
			position ++;
		}
		else if (string[position] == '#')
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
	}
	if (string[position] == 'c')
	{
		
	}
	return (position);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		lenght;
	t_print	*tab;

	lenght = 0;
	i = -1;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	initialize_tab(tab);
	va_start(tab->args, string);
	while (string[++i] != '\0')
	{
		if (string[i] == '%')
			i = get_formatting(tab, string, i + 1);
		else
			lenght += write(1, &string[i], 1);
	}
	va_end(tab->args);
	lenght += tab->len;
	free(tab);
	return (lenght);
}
