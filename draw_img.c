/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:16:13 by avaures           #+#    #+#             */
/*   Updated: 2022/10/04 18:02:08 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	drawceiling(int x, int start, int end, t_vars *vars)
{
	int	i;
	(void)end;
	i = start;
//	printf("\n%d ---> start | %d ---> end\n", start, end);
	while (i < end)
	{
		my_mlx_pixel_put(&vars->img, x, i, vars->CEILINGCOLOR);
		i++;
	}
}

void	draw_wall(int x, int start, int end, t_vars *vars)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (vars->side == 1)
            my_mlx_pixel_put(&vars->img, x, i, 0xFF0000 / 2);
        else
            my_mlx_pixel_put(&vars->img, x, i, 0xFF0000);
		i++;
	}
}

void	drawfloor(int x, int start, int end, t_vars *vars)
{
	int	i;

	i = start;
	while (i < end)
	{
		my_mlx_pixel_put(&vars->img, x, i, vars->FLOORCOLOR);
		i++;
	}
}

void	drawline(int x, int y1, int y2, t_vars *vars)
{
	drawceiling(x, 0, y1, vars);
	draw_wall(x, y1, y2, vars);
	drawfloor(x, y2, HEIGHT, vars);
}
void where_draw(t_vars *v_cast)
{
	if(v_cast->drawStart < 0)
		v_cast->drawStart = 0;
	if(v_cast->drawEnd >= HEIGHT)
		v_cast->drawEnd = HEIGHT - 1;
}