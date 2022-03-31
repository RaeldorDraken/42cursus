/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:01:25 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/29 10:28:00 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include"libft.h"
# include<stdarg.h>

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
	int		percent;
	int		space;
}	t_print;

int		ft_printf(const char *string, ...);
int		ft_putstr_len(char *str);
int		get_formatting(t_print *tab, char *string, int position);
int		first_format(t_print *tab, char *string, int position);
int		second_format(t_print *tab, char *string, int position);
int		ft_putnbr_base(unsigned long int nbr, char *base, int len);

char	*ft_uitoa(unsigned int n);
char	*ft_revstr(char *s);

size_t	ft_getintsize(int n);

void	ft_print_tab(t_print *tab, char *string, int position);
void	ft_tab_char(t_print *tab);
void	ft_tab_string(t_print *tab);
void	ft_tab_pointer(t_print *tab);
void	ft_tab_decimal(t_print *tab);
void	ft_tab_integer(t_print *tab);
void	ft_tab_unsigned(t_print *tab);
void	ft_tab_hexmin(t_print *tab);
void	ft_tab_hexmax(t_print *tab);
void	ft_putchar(char c);

#endif
