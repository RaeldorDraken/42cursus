/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_args_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:43:24 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/21 12:07:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tab_integer(t_print *tab)
{
	char	*arg;

	arg = ft_itoa(va_arg(tab->args, int));
	tab->len += ft_putstr_len(arg);
	free (arg);
}

void	ft_tab_unsigned(t_print *tab)
{
	unsigned int	argn;
	char			*arg;

	argn = va_arg(tab->args, unsigned int);
	arg = ft_uitoa(argn);
	tab->len += ft_putstr_len(arg);
	free (arg);
}

void	ft_tab_hexmin(t_print *tab)
{
	unsigned int	arg;

	arg = va_arg(tab->args, unsigned int);
	tab->len += ft_putnbr_base(arg, "0123456789abcdef", 1);
}

void	ft_tab_hexmax(t_print *tab)
{
	unsigned int	arg;

	arg = va_arg(tab->args, unsigned int);
	tab->len += ft_putnbr_base(arg, "0123456789ABCDEF", 1);
}
