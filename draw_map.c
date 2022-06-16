/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:46:43 by avaures           #+#    #+#             */
/*   Updated: 2022/06/16 19:07:19 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_cube(t_vars *vars, t_coords *coord, int color)
{	
//	printf("y0 vaut %d\n", coord->y0);
	int tmpx;
	int tmpy;
	
	tmpx = coord->x0;
	tmpy = coord->y0;
//	printf("x0 vaut %d\n", coord->x0);
	while(tmpy < coord->y0 + 49)
	{
		tmpx = coord->x0;
		while (tmpx < coord->x0 + 49)
		{	
	//	printf("ici\n");
			if (color)
				my_mlx_pixel_put(&vars->img, tmpx, tmpy, 0x00FFFFFF);
			else
				my_mlx_pixel_put(&vars->img, tmpx, tmpy, 0x00000000);
		tmpx += 1;
		}
		tmpy += 1;
	}
}

void    draw_map(t_vars *vars)
{
	t_coords coord;
	
	coord.i = 0;
	coord.x = 0;
	coord.y = 0;
	coord.y0 = 0;
	coord.mapy = vars->line_map;
    coord.mapx = vars->setmap[coord.i][0];
   while(coord.y < coord.mapy)
	{
	//	printf("%d eme ligne\n", coord.y);
		coord.z = 0;
		coord.x0 = 0;
		while (coord.z < coord.mapx)
		{
	//		printf("a la colonne %d, la val est %d \n", coord.z, vars->final_tab[coord.x]);
			if (vars->final_tab[coord.x] == 1)
				draw_cube(vars, &coord, vars->final_tab[coord.x]);
			else
				draw_cube(vars, &coord, vars->final_tab[coord.x]);
			coord.x0 += 50;//x*vars->size_tab;
			coord.z++;
			coord.x++;
		}
		coord.y0 += 50;//y*vars->size_tab;
		coord.y++;
		coord.i++;
		if (coord.i < coord.mapy)
			coord.mapx = vars->setmap[coord.i][0];
	}
}