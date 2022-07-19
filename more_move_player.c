/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_move_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:03:32 by avaures           #+#    #+#             */
/*   Updated: 2022/07/19 20:03:04 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		rotate(&vars->rc.dir, -PI / 16);
	if (vars->right)
		rotate(&vars->rc.dir, PI / 16);
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