/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:31:25 by avaures           #+#    #+#             */
/*   Updated: 2022/06/15 19:20:57 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	exit_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
int		player(void *vars)
{
	static int startx = -1;
	static int starty = -1;
	int	i;
	int	j;
	//int x;
    //int x0;
    //int y;
    //int y0;
	int	mapx;
	int	mapy;

    i = 0;
    //x = 0;
    //x0 = 0;
    //y = 0;
    //y0 = 0;
	t_vars *v_cast = (t_vars *)vars;
    mapy = v_cast->line_map;
    mapx = v_cast->setmap[i][0];
	if ((startx != mapx) || starty != mapy)
	{
		v_cast->img.img = mlx_new_image(v_cast->mlx, 1920, 1080);
		v_cast->img.addr = mlx_get_data_addr(v_cast->img.img, \
		&v_cast->img.bits_per_pixel, &v_cast->img.line_length, &v_cast->img.endian);
		
		// while(y < mapy)
		// {
		// 	//y0 = y*v_cast->size_tab;
		// 	while (x < mapx)
		// 	{
		// 		y0 = y*v_cast->size_tab;
		// 		x0 = x*v_cast->size_tab;
		// 		if (v_cast->final_tab[y*mapx+x] == 1 || v_cast->final_tab[y*mapx+x] == ' ')
		// 			my_mlx_pixel_put(&v_cast->img, x0, y0, 0x00FFFFFF);
		// 		else
		// 			my_mlx_pixel_put(&v_cast->img, x0, y0, 0x00000000);           
		// 		x++;
		// 	//	printf("ok\n");
		// 	}
		// 	// x0 = x*v_cast->size_tab;
		// 	// y0 = y*v_cast->size_tab;
       	// 	y++;
        // 	i++;
        // 	mapx = v_cast->setmap[i][0];
		// }
	//	printf("ici\n");
		i = -1;	
		while(++i < v_cast->plen)
		{
			j = -1;
			while (++j < v_cast->plen)
				my_mlx_pixel_put(&v_cast->img, v_cast->px + i, v_cast->py + j, 0x00F1FF00);
		}
		mlx_put_image_to_window(v_cast->mlx, v_cast->win, v_cast->img.img, 0, 0);
	//	mlx_destroy_image(v_cast->mlx, v_cast->win);
		startx = v_cast->px;
		starty = v_cast->py;
	}
	return (0);		
}

int	close_cross(t_vars *vars)
{
	exit_game(vars);
	return (0);
}

int	ftclose(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		exit_game(vars);
	return (0);
}