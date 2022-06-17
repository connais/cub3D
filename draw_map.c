/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:46:43 by avaures           #+#    #+#             */
/*   Updated: 2022/06/17 16:43:17 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	find_box(t_vars *vars, int x, int y)
{
	int i;
	int	size;

	i = 0;
	size = 0;
	while (i < y)
	{
		size += vars->setmap[i][0];
		i++;
	}
	size += x;
	return(vars->final_tab[size]);
}

int	out_map(t_vars *vars, int x, int y, int keycode)
{
	if (y == 0 && keycode == 119)
		return (1);
	if (x == 0 && keycode == 97)
		return (1);
	if (y == vars->line_map - 1 && keycode == 115)
		return (1);
	if (x == vars->setmap[y][0] && keycode == 100)
		return (1);
	return (0);
}

int	check_move(t_vars *vars, int keycode)
{
	//keycode : 119 lettre W(haut)
	//keycode : 97 lettre A(gauche)
	//keycode : 115 lettre S(bas)
	//keycode : 100 lettre D(droite)	
	
	if (keycode == 119)
	{
		if (vars->py % 50 == 0)
		{
			if (out_map(vars, vars->px / 50, vars->py / 50, keycode) == 1)
				return (1);
			if (find_box(vars, vars->px / 50, vars->py / 50 - 1) == 1)
				return (1);
		}
	}
	if (keycode == 97)
	{
		if (vars->px % 50 == 0)
		{
			if (out_map(vars, vars->px / 50, vars->py / 50, keycode) == 1)
				return (1);
			if (find_box(vars, vars->px / 50 - 1, vars->py / 50) == 1)
				return (1);
		}
	}
	if (keycode == 115)
	{
		if (vars->py % 50 == 40)
		{
			if (out_map(vars, vars->px / 50, vars->py / 50, keycode) == 1)
				return (1);
			if (find_box(vars, vars->px / 50, vars->py / 50 + 1) == 1)
				return (1);
		}
	}
	if (keycode == 100)
	{
		if (vars->px % 50 == 40)
		{
			if (out_map(vars, vars->px / 50, vars->py / 50, keycode) == 1)
				return (1);
			if (find_box(vars, vars->px / 50 + 1, vars->py / 50) == 1)
				return (1);
		}
	}
	return (0);
}


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