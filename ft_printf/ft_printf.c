/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:43:08 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/15 12:57:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	read_format(char c)
{
	if (c == '%')
		return (format_percent());
	else
		return (0);
}

int	ft_printf(const char *string, ...)
{
	int			lenght;
	int			len;
	va_list		arg_count;
	static char	*str;

	lenght = 0;
	len = 0;
	va_start(arg_count, string);
	if (!string)
		return (0);
	else
		lenght = ft_strlen(string);
	str = ft_strdup(string);
	while (len < lenght)
	{
		len += sp_putstr(str + len);
		len ++;
	}
	free(str);
	return (lenght);
}

int	get_arg_count(char *str)
{
	int	result;

	result = 0;
	while (str)
	{
		if (*str == '%')
		{
			result ++;
			str += 2;
		}
		else
			str = ft_strchr(str, '%');
	}
	return (result);
}
