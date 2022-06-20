/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:31:25 by avaures           #+#    #+#             */
/*   Updated: 2022/06/20 18:54:44 by avaures          ###   ########.fr       */
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
	static int startxl = -1;
	static int startyl = -1;
	int	i;
	int	j;
	int xl;
	int yl;
    i = 0;
	t_vars *v_cast = (t_vars *)vars;
	//printf("x vaut %f et y vaut %f", v_cast->px, v_cast->py);
	xl = (v_cast->px + 5) + v_cast->pdx;
	yl = (v_cast->py + 5) + v_cast->pdy;
	
	if ((startx != v_cast->px) || starty != v_cast->py || startxl != xl || startyl != yl)
	{	
		mlx_destroy_image(v_cast->mlx, v_cast->img.img);
		v_cast->img.img = mlx_new_image(v_cast->mlx, 1920, 1080);
		v_cast->img.addr = mlx_get_data_addr(v_cast->img.img, \
		&v_cast->img.bits_per_pixel, &v_cast->img.line_length, &v_cast->img.endian);
		draw_map(v_cast);
		i = -1;	
		while(++i < v_cast->plen)
		{
			j = -1;
			while (++j < v_cast->plen)
				my_mlx_pixel_put(&v_cast->img, v_cast->px + i, v_cast->py + j, 0x00F1FF00);
		}
		i = -1;
		while (++i < v_cast->plen)
				my_mlx_pixel_put(&v_cast->img, xl, yl - i, 0x00F1FF00);
		mlx_put_image_to_window(v_cast->mlx, v_cast->win, v_cast->img.img, 0, 0);
		startx = v_cast->px;
		startxl = xl;
		startyl = yl;
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