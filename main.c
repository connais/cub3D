/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:11:41 by avaures           #+#    #+#             */
/*   Updated: 2022/06/15 19:00:46 by avaures          ###   ########.fr       */
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

// #define COLUMN_SIZE x
// #define ROW_SIZE y
// get_coord( int x, int y )
// {
// 	if ( x > ROW_SIZE )
// 		return -1;
// 	if ( y > COLUMN_SIZE )
// 		return -1;
// 	tab[ x + y * ROW_SIZE];
// }

int main(int argc, char **argv)

{
	t_vars	vars;

    if (argc != 2)
        return (1);
    if (parsing(&vars, argv[1]) != 0)
		return (1);
	vars.map = save_map(vars.filecub);
	// int i;
	// i = 0;
	// while (vars.map[i])
	// {
	// 	printf("%s\n", vars.map[i]);
	// 	i++;
	// }
	vars.setmap = set_map(vars.filecub);
	vars.line_map = line_map(vars.filecub);
	vars.final_tab = final_tab(&vars);
	vars.px = 400;
	vars.py = 500;
	vars.plen = 10;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, ftclose, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_cross, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, 10, 10);
//	mlx_key_hook(vars.win, moove, &vars);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
//	draw_map(&vars);
	mlx_loop_hook(vars.mlx, player, (void *)&vars);
	mlx_loop(vars.mlx);
}
