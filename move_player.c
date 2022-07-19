/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:37:51 by avaures           #+#    #+#             */
/*   Updated: 2022/07/19 16:05:43 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int inttoint(t_vars *vars, int x, int y)
{
		int	i;
		int	res;
		
		i = -1;
		res = 0;
		while (++i < y - 1)
			res += vars->setmap[i][0];
		return (res + x - 1);
}

t_pos	*rotate(t_pos *dir, double angle)
{
	double oldPlaneX;
	
	//printf("kek\n");
	oldPlaneX = dir->x;
    dir->x = oldPlaneX * cos(angle) - dir->y * sin(angle);
    dir->y = oldPlaneX * sin(angle) + dir->y * cos(angle);
	return (dir);
}

void	translate(t_pos *pos, t_pos *dir)
{
	pos->x += dir->x * STEP;
	pos->y += dir->y * STEP;
}	

int		is_valid_move(t_vars *vars, t_pos dir, t_pos pos)
{
	translate(&pos, &dir);
	//printf(" %d\n", vars->final_tab[inttoint(vars, pos.x, pos.y)]);
	if (vars->final_tab[inttoint(vars, (int)(pos.x + dir.x * 0.1), (int)(pos.y + dir.y * 0.1))] == 0)
	{
		return (1);
	}
	//printf("hello\n");
	return (0);
}

void	move(t_vars *vars, int move)
{
	t_pos dir;
	t_pos pos;

	dir.x = vars->rc.dir.x;
	dir.y = vars->rc.dir.y;
	rotate(&dir, move * PI / 2);
	//printf("dirx = %lf | diry = %lf\n", dir.x, dir.y);
	pos.x = vars->rc.pos.x;
	pos.y = vars->rc.pos.y;
	if (is_valid_move(vars, dir, pos))
	{
		//printf("hello\n");
		translate(&vars->rc.pos, &dir);
	}
}