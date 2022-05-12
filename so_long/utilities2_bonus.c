/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:33:24 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/12 13:18:42 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

void	frame_cycle(t_vars *vars)
{
	if (vars->fps > 0)
		vars->fps --;
	else
	{
		vars->fps = 8;
		if (vars->frame > 6)
			vars->frame = 0;
		else
			vars->frame ++;
	}
	if (vars->frame == 1 || vars->frame == 5)
		vars->edir = -1;
	else if (vars->frame == 0 || vars->frame == 2)
		vars->edir = 2;
	else if (vars->frame == 3 || vars->frame == 6)
		vars->edir = -2;
	else if (vars->frame == 4 || vars->frame == 7)
		vars->edir = 1;
}

void	bonus_operators(t_vars *vars, char *movstr)
{
	frame_cycle(vars);
	animate_frame("./sprites/", vars, 1);
	animate_frame("./sprites/coin_", vars, 3);
	animate_frame("./sprites/mine_", vars, 5);
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0x00000000, movstr);
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0x00FF0000, movstr);
	enemymove(vars);
}

void	swap_tiles2(t_vars *vars, int y, int x)
{
	if (vars->edir == -1)
	{
		if (vars->level[y][x - 1] == '0')
		{
			vars->level[y][x - 1] = 'M';
			vars->level[y][x] = '0';
		}
	}
	else if (vars->edir == 1)
	{
		if (vars->level[y][x + 1] == '0')
		{
			vars->level[y][x + 1] = 'M';
			vars->level[y][x] = '0';
		}
	}
	else
		swap_tiles3(vars, y, x);
}

void	swap_tiles3(t_vars *vars, int y, int x)
{
	if (vars->edir == -2)
	{
		if (vars->level[y - 1][x] == '0')
		{
			vars->level[y - 1][x] = 'M';
			vars->level[y][x] = '0';
		}
	}
	else if (vars->edir == 2)
	{
		if (vars->level[y + 1][x] == '0')
		{
			vars->level[y + 1][x] = 'M';
			vars->level[y][x] = '0';
		}
	}
}

void	enemymove(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	if (vars->fps == 0)
	{
		while (y < vars->maph)
		{	
			x = 0;
			while (x < vars->mapw)
			{
				if (check_tile(vars->level[y][x]) == 'M')
				{
					swap_tiles2(vars, y, x);
				}
				x ++;
			}
			y ++;
		}
	}
}
