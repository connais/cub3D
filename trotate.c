/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:03:07 by avaures           #+#    #+#             */
/*   Updated: 2022/07/19 12:41:16 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_image(t_vars *vars)
{
	ft_bzero(vars->img.addr, HEIGHT * WIDTH * 4);
}

// Utiliser un get_dir au lieu de rotate
void	apply_moves(t_vars *vars) 
{
	//printf("up = %d | left = %d | down = %d | right = %d\n", vars->up, vars->strafe_left, vars->down, vars->strafe_right);
	if (vars->up)
		move(vars, 0);
	if (vars->strafe_left)
		move(vars, 1);
	if (vars->down)
		move(vars, 2);
	if (vars->strafe_right)
		move(vars, 3);
	if (vars->left)
		rotate(&vars->rc.dir, -PI / 16);
	if (vars->right)
		rotate(&vars->rc.dir, PI / 16);
}

void	plane_calc(t_vars *vars)
{
	vars->rc.plane.x = vars->rc.dir.x;
	vars->rc.plane.y = vars->rc.dir.y;
	rotate(&vars->rc.plane, PI / 2);
}

void	update_rc_vars(t_vars *vars)
{
	apply_moves(vars);
	plane_calc(vars);
}

int calculate(void *vars)
{
	t_vars *v_cast = (t_vars *)vars;


//	UPDATE VARS (chaque tour mlx_loop())

	//printf("posx = %lf | posy = %lf | dirx = %lf | diry = %lf | planex = %lf | planey = %lf\n", v_cast->rc.pos.x, v_cast->rc.pos.y, v_cast->rc.dir.x, v_cast->rc.dir.y, v_cast->rc.plane.x, v_cast->rc.plane.y);
	update_rc_vars(v_cast);
	reset_image(vars);

	////printf("\n retour fonction : %d\n", inttoint(v_cast, 11, 12));
    // //printf("ok\n");
		int x = -1;
		while (++x < WIDTH)
		{
			v_cast->rc.camplanex = 2.0 * (double)x / (double)WIDTH - 1.0;
			v_cast->rc.raydir.x = v_cast->rc.dir.x + v_cast->rc.plane.x * v_cast->rc.camplanex;
			v_cast->rc.raydir.y = v_cast->rc.dir.y + v_cast->rc.plane.y * v_cast->rc.camplanex;
			v_cast->rc.map.x = (int)v_cast->rc.pos.x;
			v_cast->rc.map.y = (int)v_cast->rc.pos.y;
			if (v_cast->rc.raydir.x <= 0.00001 && v_cast->rc.raydir.x >= -0.00001) 
				v_cast->rc.deltadist.x = 1e30;
			else
				v_cast->rc.deltadist.x = fabs(1.0 / v_cast->rc.raydir.x);
			if (v_cast->rc.raydir.y <= 0.00001 && v_cast->rc.raydir.y >= -0.00001)
				v_cast->rc.deltadist.y = 1e30;
			else
				v_cast->rc.deltadist.y = fabs(1.0 / v_cast->rc.raydir.y);
			double perpWallDist;
			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

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
			
			while (hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
				if (v_cast->rc.sidedist.x < v_cast->rc.sidedist.y)
				{
					v_cast->rc.sidedist.x += v_cast->rc.deltadist.x;
					v_cast->rc.map.x += v_cast->rc.step.x;
					side = 0;
				}
				else
				{
					v_cast->rc.sidedist.y += v_cast->rc.deltadist.y;
					v_cast->rc.map.y += v_cast->rc.step.y;
					side = 1;
				}
				//Check if ray has hit a wall
				if (v_cast->final_tab[inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y)] > 0) 
					hit = 1;
			}
			// //printf("\nok\n");

			if(side == 0) 
				perpWallDist = (v_cast->rc.sidedist.x - v_cast->rc.deltadist.x);
			else
				perpWallDist = (v_cast->rc.sidedist.y - v_cast->rc.deltadist.y);
			//printf("perpwalldist = %lf\n", perpWallDist);
			////printf("perpwalldist : %f\n", perpWallDist);
			int lineHeight = (int)(HEIGHT / perpWallDist);
			//printf("lineheight : %d\n", lineHeight);
			v_cast->drawStart = -lineHeight / 2 + HEIGHT / 2;
			v_cast->drawEnd = lineHeight / 2 + HEIGHT / 2;
			////printf("lineheight : %d\nHEIGHT : %d\n", lineHeight, HEIGHT);
			//printf("drawstart : %d\ndrawend : %d\n", v_cast->drawStart, v_cast->drawEnd);
			if(v_cast->drawStart < 0)
				v_cast->drawStart = 0;
			if(v_cast->drawEnd >= HEIGHT)
				v_cast->drawEnd = HEIGHT - 1;
			
			int color;
			if (inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y) == 1)
			{
	//			//printf("enter\n");
				color = 0x00FF0000; //red
			}
			else if (inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y) == 2)  
				color = 0x0000FF00; //green
			else if (inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y) == 3) 
				color = 0x000000FF; //blue
			else if (inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y) == 4)   
				color = 0x00FFFFFF; //white
			else 
				color = 0x0000FFFF; //yellow
			if (side == 1) 
				color = color / 2;
		//	//printf("\n%d\n", x);
			drawline(x, v_cast->drawStart, v_cast->drawEnd, v_cast);
//			//printf("ici\n");
    	}
		mlx_put_image_to_window(v_cast->mlx, v_cast->win, v_cast->img.img, 0, 0);
  return (0);
}


void	init_vars(t_vars *vars)
{
	vars->rc.pos.x = 6.5;
    vars->rc.pos.y = 2.5;
    vars->rc.dir.x = -1;
    vars->rc.dir.y = 0;
    vars->rc.plane.x = vars->rc.dir.x;
    vars->rc.plane.y = vars->rc.dir.y;
	vars->up = 0;
	vars->left = 0;
	vars->down = 0;
	vars->right = 0;
	vars->strafe_left = 0;
	vars->strafe_right = 0;
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
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 3, 1L<<1, keyrelease, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_cross, &vars);
//	mlx_key_hook(vars.win, keyk_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_loop_hook(vars.mlx, calculate, (void *)&vars);
	mlx_loop(vars.mlx);
}

