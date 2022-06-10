/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:31:25 by avaures           #+#    #+#             */
/*   Updated: 2022/06/10 17:32:20 by avaures          ###   ########.fr       */
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
void	player(t_vars vars)
{
	int	i;
	int	j;
	
	i = -1;
	while(++i < vars.plen)
	{
		j = -1;
		while (++j < vars.plen)
			my_mlx_pixel_put(&vars.img, vars.px, vars.py + j, 0x00F1FF00);
		vars.px++;
	}
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