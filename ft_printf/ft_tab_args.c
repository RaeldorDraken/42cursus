/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:43:24 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/21 12:21:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

void	ft_tab_char(t_print *tab)
{
	char	arg;

	arg = va_arg(tab->args, int);
	tab->len += write(1, &arg, 1);
}

void	ft_tab_string(t_print *tab)
{
	char	*arg;

	arg = va_arg(tab->args, char *);
	if (!arg)
		arg = "(null)";
	tab->len += ft_putstr_len(arg);
}

void	ft_tab_pointer(t_print *tab)
{
	unsigned long	arg;

	arg = va_arg(tab->args, unsigned long);
	tab->len += write(1, "0x", 2);
	tab->len += ft_putnbr_base(arg, "0123456789abcdef", 1);
}

void	ft_tab_decimal(t_print *tab)
{
	char	*arg;

	arg = ft_itoa(va_arg(tab->args, int));
	tab->len += ft_putstr_len(arg);
	free (arg);
}
