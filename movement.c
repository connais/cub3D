/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:55:43 by avaures           #+#    #+#             */
/*   Updated: 2022/07/13 16:55:15 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//int rotate()
/*
int translate(t_vars *vars)
{
    
}
*/

int    found_player(t_vars *vars)
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
			if (vars->final_tab[coord.x] == 2 || vars->final_tab[coord.x] == 3 || \
			vars->final_tab[coord.x] == 4 || vars->final_tab[coord.x] == 5)
			{
				vars->px = coord.x0;
				vars->py = coord.y0;
			}
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
	return 0;
}
void draw_player(t_vars *v_cast)
{
	int i;
	int j;
	
	i = -1;	
	while(++i < v_cast->plen)
	{
		j = -1;
		while (++j < v_cast->plen)
			my_mlx_pixel_put(&v_cast->img, v_cast->px + i, v_cast->py + j, 0x00F1FF00);
	}
}
int keypress(int key, t_vars *vars)
{
	if (key == 65307)
		close_cross(vars);
	if (key == 119)
	{
	 	 vars->px += vars->pdx;
	 	 vars->py += vars->pdy;
		vars->py -= 5;		
	}
	if (key == 97)
		vars->px -= 5;
	if (key == 115)
		vars->py += 5;
	if (key == 100)
		vars->px += 5;
	if (key == 65361)
	{
		vars->pa -= 0.1;
		if (vars->pa < 0)
			vars->pa += 2 * PI;
		vars->pdx = cosf(vars->pa) * 5;
		vars->pdy = sinf(vars->pa) * 5;
	}
	if (key == 65363)
	{
		vars->pa += 0.1;
		if (vars->pa > 2 * PI)
			vars->pa -= 2 * PI;
		vars->pdx = cosf(vars->pa) * 5;
		vars->pdy = sinf(vars->pa) * 5;
	}
	return (0);
}