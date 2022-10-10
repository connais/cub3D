/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:40:47 by avaures           #+#    #+#             */
/*   Updated: 2022/10/05 15:27:18 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	start_calc(t_vars *v_cast, int x)
{
	v_cast->rc.camplanex = 2.0 * (double)x / (double)WIDTH - 1.0;
			v_cast->rc.raydir.x = v_cast->rc.dir.x + v_cast->rc.plane.x * v_cast->rc.camplanex;
			v_cast->rc.raydir.y = v_cast->rc.dir.y + v_cast->rc.plane.y * v_cast->rc.camplanex;
			v_cast->rc.map.x = (int)v_cast->rc.pos.x;
			v_cast->rc.map.y = (int)v_cast->rc.pos.y;
}

void	calc_dist(t_vars *v_cast)
{	
	if (v_cast->rc.raydir.x <= 0.00001 && v_cast->rc.raydir.x >= -0.00001) 
		v_cast->rc.deltadist.x = 1e30;
	else
		v_cast->rc.deltadist.x = fabs(1.0 / v_cast->rc.raydir.x);
	if (v_cast->rc.raydir.y <= 0.00001 && v_cast->rc.raydir.y >= -0.00001)
		v_cast->rc.deltadist.y = 1e30;
	else
		v_cast->rc.deltadist.y = fabs(1.0 / v_cast->rc.raydir.y);
}

void	calc_side(t_vars *v_cast)
{

	v_cast->hit = 0; //was there a wall hit?
	if (v_cast->rc.raydir.x < 0)
	{
		v_cast->rc.step.x = -1;
		v_cast->rc.sidedist.x = (v_cast->rc.pos.x - v_cast->rc.map.x) * v_cast->rc.deltadist.x;
	}
	else
	{
		v_cast->rc.step.x = 1;
		v_cast->rc.sidedist.x = (v_cast->rc.map.x + 1.0 - v_cast->rc.pos.x) * v_cast->rc.deltadist.x;
	}
	if (v_cast->rc.raydir.y < 0)
	{
		v_cast->rc.step.y = -1;
		v_cast->rc.sidedist.y = (v_cast->rc.pos.y - v_cast->rc.map.y) * v_cast->rc.deltadist.y;
	}
	else
	{
		v_cast->rc.step.y = 1;
		v_cast->rc.sidedist.y = (v_cast->rc.map.y + 1.0 - v_cast->rc.pos.y) * v_cast->rc.deltadist.y;
	}			
}

void	found_hit(t_vars *v_cast)
{
	while (v_cast->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (v_cast->rc.sidedist.x < v_cast->rc.sidedist.y)
		{
			v_cast->rc.sidedist.x += v_cast->rc.deltadist.x;
			v_cast->rc.map.x += v_cast->rc.step.x;
			v_cast->side = 0;
		}
		else
		{
			v_cast->rc.sidedist.y += v_cast->rc.deltadist.y;
			v_cast->rc.map.y += v_cast->rc.step.y;
			v_cast->side = 1;
		}
		//Check if ray has v_cast->hit a wall
		if (v_cast->final_tab[inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y)] > 0) 
			v_cast->hit = 1;
	}
}
void	which_walldist(t_vars *v_cast, double *perpWallDist)
{
	if(v_cast->side == 0) 
		*perpWallDist = (v_cast->rc.sidedist.x - v_cast->rc.deltadist.x);
	else
		*perpWallDist = (v_cast->rc.sidedist.y - v_cast->rc.deltadist.y);
}