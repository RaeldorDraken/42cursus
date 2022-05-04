/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/04 12:34:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	ft_strchk(char *s, int c)
{
	int	l;
	int	i;
	int	result;

	l = ft_strlen(s)-1;
	i = 0;
	result = 0;
	while (i < l)
	{
		if (s[i] == c)
			result ++;
		i ++;
	}
	return (result);
}	

//Checktile returns:
//return 0 = empty tile;
//return 1 = player;
//return 2 = wall tile;
//return 3 = coin;
//return 4 = exit;
//return 5 = enemy;
int	check_tile(char c)
{
	if (c == 'P')
		return (1);
	else if (c == '1')
		return (2);
	else if (c == 'C')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'M')
		return (5);
	return (0);
}

void	swap_tiles(t_vars *vars, int y, int x)
{
	vars->level[y][x] = 'P';
	vars->level[vars->ply][vars->plx] = '0';
}

int	move_player2(t_vars *vars, int keycode)
{
	if (keycode == 1)
	{
		if (check_tile(vars->level[vars->ply + 1][vars->plx]) != 2)
		{
			swap_tiles(vars, vars->ply + 1, vars->plx);
			return (1);
		}
	}
	else if (keycode == 13)
	{
		if (check_tile(vars->level[vars->ply - 1][vars->plx]) != 2)
		{
			swap_tiles(vars, vars->ply - 1, vars->plx);
			return (1);
		}
	}
	return (0);
}

int	move_player(t_vars *vars, int keycode)
{
	if (keycode == 2)
	{
		if (check_tile(vars->level[vars->ply][vars->plx + 1]) != 2)
		{
			swap_tiles(vars, vars->ply, vars->plx + 1);
			return (1);
		}
	}
	else if (keycode == 0)
	{
		if (check_tile(vars->level[vars->ply][vars->plx - 1]) != 2)
		{
			swap_tiles(vars, vars->ply, vars->plx - 1);
			return (1);
		}
	}
	else
	{
		if (move_player2(vars, keycode))
			return (1);
		else
			return (0);
	}
	return (0);
}
