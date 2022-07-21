/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:11:41 by avaures           #+#    #+#             */
/*   Updated: 2022/07/21 14:19:08 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook(int keycode, t_vars *vars)
{
	//keycode : 119 lettre W(haut)
	//keycode : 97 lettre A(gauche)
	//keycode : 115 lettre S(bas)
	//keycode : 100 lettre D(droite)
	//keycode : 65361 fleche gauche
	//keycode : 65363 fleche droite
	//printf("%d\n", keycode);
	if (check_move(vars, keycode) == 1)
		return (0);
	if (keycode == 65361)
	{
		vars->pa -= 0.1;
		if (vars->pa < 0)
			vars->pa += 2 * PI;
		vars->pdx = cosf(vars->pa) * 5;
		vars->pdy = sinf(vars->pa) * 5;
	}
	if (keycode == 65363)
	{
		vars->pa += 0.1;
		if (vars->pa > 2 * PI)
			vars->pa -= 2 * PI;
		vars->pdx = cosf(vars->pa) * 5;
		vars->pdy = sinf(vars->pa) * 5;
	}
	if (keycode == 119)
	{
	 	// vars->px += vars->pdx;
	 	// vars->py += vars->pdy;
		vars->py -= 5;		
	}
	if (keycode == 97)
		vars->px -= 5;
	if (keycode == 115)
		vars->py += 5;
	if (keycode == 100)
		vars->px += 5;

// 	//if S
// 	px -= pdx;
// 	py -= pdy;
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	vars;
    
	if (argc != 2)
        return (1);
    if (parsing(&vars, argv[1]) != 0)
		return (1);
	init_vars(&vars);
	vars.map = save_map(vars.filecub);
	vars.setmap = set_map(vars.filecub);
	vars.line_map = line_map(vars.filecub);
	vars.final_tab = final_tab(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.tex.img = mlx_xpm_file_to_image(vars.mlx, "./img_texture/lave.xpm", &vars.tex.width, &vars.tex.height);
	vars.tex.addr = mlx_get_data_addr(vars.tex.img, &vars.tex.bits_per_pixel, &vars.tex.line_length, &vars.tex.endian);
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 3, 1L<<1, keyrelease, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_cross, &vars);
//	mlx_key_hook(vars.win, keyk_hook, &vars);
	mlx_loop_hook(vars.mlx, calculate, (void *)&vars);
	mlx_loop(vars.mlx);
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

// int main(int argc, char **argv)
// {
// 	t_vars	vars;
// //	ft_bzero(&vars, sizeof(t_vars));
//     if (argc != 2)
//         return (1);
//     if (parsing(&vars, argv[1]) != 0)
// 		return (1);
// 	vars.map = save_map(vars.filecub);
// 	// int i;
// 	// i = 0;
// 	// while (vars.map[i])
// 	// {
// 	// 	printf("%s\n", vars.map[i]);
// 	// 	i++;
// 	// }
// 	vars.setmap = set_map(vars.filecub);
// 	vars.line_map = line_map(vars.filecub);
// 	vars.final_tab = final_tab(&vars);
// 	found_player(&vars);
// 	vars.plen = 10;
// 	vars.pa = 0;
// 	vars.pdx = cosf(vars.pa) * 5;
// 	vars.pdy = sinf(vars.pa) * 5;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
// //	mlx_hook(vars.win, 3, 1L << 1, keyrelease, &vars);
// 	mlx_hook(vars.win, 17, 1L << 17, close_cross, &vars);
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	vars.img.img = mlx_new_image(vars.mlx, 10, 10);
// //	mlx_key_hook(vars.win, moove, &vars);
// 	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
// //	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
// //	draw_map(&vars);
// 	mlx_loop_hook(vars.mlx, player, (void *)&vars);
// 	mlx_loop(vars.mlx);
// }
