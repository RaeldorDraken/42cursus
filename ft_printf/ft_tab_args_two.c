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
	char	arg;

	arg = va_arg(tab->args, int);
	tab->len += write(1, &arg, 1);
}

void	ft_tab_unsigned(t_print *tab)
{
	char	arg;

	arg = va_arg(tab->args, int);
	tab->len += write(1, &arg, 1);
}

void	ft_tab_hexmin(t_print *tab)
{
	char	arg;

	arg = va_arg(tab->args, int);
	tab->len += write(1, &arg, 1);
}

void	ft_tab_hexmax(t_print *tab)
{
	char	arg;

	arg = va_arg(tab->args, int);
	tab->len += write(1, &arg, 1);
}
