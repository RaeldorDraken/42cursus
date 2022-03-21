/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:43:08 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/21 12:36:14 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

t_print	*initialize_tab(t_print *tab)
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

int	ft_percent_case(char *string, int i)
{
	if (string[i] == '%')
	{
		return (write(1, "%", 1));
	}
	return (0);
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
		{
			i = get_formatting(tab, (char *)string, i + 1);
			lenght += ft_percent_case((char *)string, i);
		}
		else
			lenght += write(1, &string[i], 1);
	}
	va_end(tab->args);
	lenght += tab->len;
	free(tab);
	return (lenght);
}
