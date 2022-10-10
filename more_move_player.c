/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_move_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:03:32 by avaures           #+#    #+#             */
/*   Updated: 2022/10/05 15:36:09 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_rgb(t_vars *vars, char c)
{
	int		i;
	int		j;
	char	**rgbcolor;
	
	i = 0;
	j = 0;
	while (vars->filecub[i])
	{
		if (vars->filecub[i][j] == c)
		{
			j++;
			while (vars->filecub[i][j] == ' ')
				j++;
			rgbcolor = ft_split(&vars->filecub[i][j], ',');		
		}
		i++;
	}
	//LONG = B * 65536 + G * 256 + R
	j = (ft_atoi(rgbcolor[0]) * 65536) + (ft_atoi(rgbcolor[1]) * 256) + ft_atoi(rgbcolor[2]);
	printf("j : %d\n", j);
	return (j);
}

void	init_color(t_vars *vars)
{
	vars->FLOORCOLOR = get_rgb(vars, 'F');
	vars->CEILINGCOLOR = get_rgb(vars, 'C');
	//printf("std : %s\n", rgbcolor[0]);
	// printf("std : %s\n", rgbcolor[1]);
	// printf("std : %s\n", rgbcolor[2]);
	//vars->CEILINGCOLOR
}

void	init_vars(t_vars *vars)
{
	vars->rc.pos.x = 6.5;
    vars->rc.pos.y = 2.5;
    vars->rc.dir.x = -1;
    vars->rc.dir.y = 0;
    vars->rc.plane.x = vars->rc.dir.x;
    vars->rc.plane.y = vars->rc.dir.y;
	vars->up = 0;
	vars->left = 0;
	vars->down = 0;
	vars->right = 0;
	vars->strafe_left = 0;
	vars->strafe_right = 0;
    vars->height = HEIGHT;
    vars->width = WIDTH;
	init_color(vars);
}

void	apply_moves(t_vars *vars) 
{
	//printf("up = %d | left = %d | down = %d | right = %d\n", vars->up, vars->strafe_left, vars->down, vars->strafe_right);
	if (vars->up)
		move(vars, 0);
	if (vars->strafe_left)
		move(vars, 3);
	if (vars->down)
		move(vars, 2);
	if (vars->strafe_right)
		move(vars, 1);
	if (vars->left)
		rotate(&vars->rc.dir, -PI / 27);
	if (vars->right)
		rotate(&vars->rc.dir, PI / 27);
}

void	plane_calc(t_vars *vars)
{
	vars->rc.plane.x = vars->rc.dir.x;
	vars->rc.plane.y = vars->rc.dir.y;
	rotate(&vars->rc.plane, PI / 2);
}

void	update_rc_vars(t_vars *vars)
{
	apply_moves(vars);
	plane_calc(vars);
}