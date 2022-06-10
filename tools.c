/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:31:25 by avaures           #+#    #+#             */
/*   Updated: 2022/06/10 19:38:55 by avaures          ###   ########.fr       */
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
	
	i = -1;
	if ((startx != ((t_vars *)vars)->px) || starty != ((t_vars *)vars)->py)
	{
		((t_vars  *)vars)->img.img = mlx_new_image(((t_vars *)vars)->mlx, 1920, 1080);
		((t_vars *)vars)->img.addr = mlx_get_data_addr(((t_vars *)vars)->img.img, \
		&((t_vars *)vars)->img.bits_per_pixel, &((t_vars *)vars)->img.line_length, &((t_vars *)vars)->img.endian);
		while(++i < ((t_vars *)vars)->plen)
		{
			j = -1;
			while (++j < ((t_vars *)vars)->plen)
				my_mlx_pixel_put(&((t_vars *)vars)->img, ((t_vars *)vars)->px + i, ((t_vars *)vars)->py + j, 0x00F1FF00);
		}
		mlx_put_image_to_window(((t_vars *)vars)->mlx, ((t_vars *)vars)->win, ((t_vars *)vars)->img.img, 0, 0);
	//	mlx_destroy_image(((t_vars *)vars)->mlx, ((t_vars *)vars)->win);
		startx = ((t_vars *)vars)->px;
		starty = ((t_vars *)vars)->py;
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