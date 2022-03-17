/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:01:25 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/17 11:24:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include"libft.h"
# include<stdarg.h>

int		ft_printf(const char *string, ...);
char	*sp_putstr(char *str);
void	ft_putstr(char *str);
char	*printable_string(char *string);

#endif
