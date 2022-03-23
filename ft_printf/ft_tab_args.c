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

#include "ft_printf.h"

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

	arg = (unsigned long)va_arg(tab->args, void *);
	tab->len += ft_putnbr_hex(arg, 1, 0, 0);
}

void	ft_tab_decimal(t_print *tab)
{
	char	arg;

	arg = va_arg(tab->args, int);
	tab->len += write(1, &arg, 1);
}
