/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:05 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/09 17:57:15 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	check_int_max(char *num);
static int	check_int_min(char *num);

int	check_int(char *num)
{
	if (num[0] == '-')
		return (check_int_min(num));
	else
		return (check_int_max(num));
}

static int	check_int_max(char *num)
{
	size_t	len;
	char	*int_max;
	int		ret;

	int_max = ft_itoa(INT_MAX);
	if (num[0] == '+')
		num++;
	len = ft_strlen(num);
	if (len > ft_strlen(int_max))
		ret = 1;
	else if (len < ft_strlen(int_max))
		ret = 0;
	else if (ft_strncmp(num, int_max, len) > 0)
		ret = 1;
	else
		ret = 0;
	free(int_max);
	return (ret);
}

static int	check_int_min(char *num)
{
	size_t	len;
	char	*int_min;
	int		ret;

	int_min = ft_itoa(INT_MIN);
	len = ft_strlen(num);
	if (len > ft_strlen(int_min))
		ret = 1;
	else if (len < ft_strlen(int_min))
		ret = 0;
	else if (ft_strncmp(num, int_min, len) > 0)
		ret = 1;
	else
		ret = 0;
	free(int_min);
	return (ret);
}
