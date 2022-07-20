/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:03:07 by avaures           #+#    #+#             */
/*   Updated: 2022/07/20 19:03:53 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_image(t_vars *vars)
{
	ft_bzero(vars->img.addr, HEIGHT * WIDTH * 4);
}

void	calc_side(t_vars *v_cast)
{

	v_cast->hit = 0; //was there a wall hit?
	if (v_cast->rc.raydir.x < 0)
	{
		v_cast->rc.step.x = -1;
		v_cast->rc.sidedist.x = (v_cast->rc.pos.x - v_cast->rc.map.x) * v_cast->rc.deltadist.x;
	}
	else
	{
		v_cast->rc.step.x = 1;
		v_cast->rc.sidedist.x = (v_cast->rc.map.x + 1.0 - v_cast->rc.pos.x) * v_cast->rc.deltadist.x;
	}
	if (v_cast->rc.raydir.y < 0)
	{
		v_cast->rc.step.y = -1;
		v_cast->rc.sidedist.y = (v_cast->rc.pos.y - v_cast->rc.map.y) * v_cast->rc.deltadist.y;
	}
	else
	{
		v_cast->rc.step.y = 1;
		v_cast->rc.sidedist.y = (v_cast->rc.map.y + 1.0 - v_cast->rc.pos.y) * v_cast->rc.deltadist.y;
	}			
}

void	found_hit(t_vars *v_cast)
{
	while (v_cast->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (v_cast->rc.sidedist.x < v_cast->rc.sidedist.y)
		{
			v_cast->rc.sidedist.x += v_cast->rc.deltadist.x;
			v_cast->rc.map.x += v_cast->rc.step.x;
			v_cast->side = 0;
		}
		else
		{
			v_cast->rc.sidedist.y += v_cast->rc.deltadist.y;
			v_cast->rc.map.y += v_cast->rc.step.y;
			v_cast->side = 1;
		}
		//Check if ray has v_cast->hit a wall
		if (v_cast->final_tab[inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y)] > 0) 
			v_cast->hit = 1;
	}
}

int calculate(void *vars)
{
	t_vars *v_cast = (t_vars *)vars;
	int x;
	double perpWallDist;
	int lineHeight;
	x = -1;
	update_rc_vars(v_cast);
	reset_image(vars);
	while (++x < WIDTH)
	{
		v_cast->hit = 0;
		start_calc(v_cast, x);	
		calc_dist(v_cast);
		calc_side(v_cast);
		found_hit(v_cast);
		if(v_cast->side == 0) 
			perpWallDist = (v_cast->rc.sidedist.x - v_cast->rc.deltadist.x);
		else
			perpWallDist = (v_cast->rc.sidedist.y - v_cast->rc.deltadist.y);
		lineHeight = (int)(HEIGHT / perpWallDist);
		v_cast->drawStart = -lineHeight / 2 + HEIGHT / 2;
		v_cast->drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(v_cast->drawStart < 0)
			v_cast->drawStart = 0;
		if(v_cast->drawEnd >= HEIGHT)
			v_cast->drawEnd = HEIGHT - 1;
		drawline(x, v_cast->drawStart, v_cast->drawEnd, v_cast);
		//calc_text(v_cast, x);
    	}
	mlx_put_image_to_window(v_cast->mlx, v_cast->win, v_cast->img.img, 0, 0);
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

