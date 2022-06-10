/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:11:41 by avaures           #+#    #+#             */
/*   Updated: 2022/06/10 19:28:29 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
int	key_hook(int keycode, t_vars *vars)
{
	//keycode : 119 lettre W(haut)
	//keycode : 97 lettre A(gauche)
	//keycode : 115 lettre S(bas)
	//keycode : 100 lettre D(droite)
	
	//printf("%d\n", keycode);
	if (keycode == 119)
		vars->py -= 5;		
	if (keycode == 97)
		vars->px -= 5;
	if (keycode == 115)
		vars->py += 5;
	if (keycode == 100)
		vars->px += 5;
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.px = 400;
	vars.py = 500;
	vars.plen = 10;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, ftclose, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_cross, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
//	mlx_key_hook(vars.win, moove, &vars);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	//player(vars);
	mlx_loop_hook(vars.mlx, player, (void *)&vars);
	mlx_loop(vars.mlx);
}
