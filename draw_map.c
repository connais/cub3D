/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:46:43 by avaures           #+#    #+#             */
/*   Updated: 2022/06/15 15:42:41 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    draw_map(t_vars *vars)
{
    int x;
    int x0;
    int y;
    int y0;
    int i;

    i = 0;
    x = 0;
    x0 = 0;
    y = 0;
    y0 = 0;
    vars->py = vars->line_map;
    vars->px = vars->setmap[i][0];
    printf("ok\n");
    vars->img.img = mlx_new_image(&vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
    while(y < vars->py)
	{
        printf("ok\n");
		while (x < vars->px)
        {
		    if (vars->map[x][y * vars->px + x] == '1' || vars->map[x][y * vars->px + x] == ' ')
                my_mlx_pixel_put(&vars->img, x0++, y0++, 0x00FFFFFF);
            else
                my_mlx_pixel_put(&vars->img, x0++, y0++, 0x00FFFFFF);           
            x++;
        }
        y++;
        i++;
        vars->px = vars->setmap[i][0];
	}
	mlx_put_image_to_window(&vars->mlx, &vars->win, &vars->img.img, 0, 0);
}