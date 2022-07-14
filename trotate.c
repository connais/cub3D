/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:03:07 by avaures           #+#    #+#             */
/*   Updated: 2022/07/14 19:56:39 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int inttoint(t_vars *vars, int x, int y)
{
		int	i;
		int	res;
		
		i = -1;
		res = 0;
		while (++i < y - 1)
			res += vars->setmap[i][0];
		return (res + x - 1);
}
	
void	drawline(int x, int y1, int y2, int color, t_vars *vars)
{
	int	y = y2;
	(void)y1;
	my_mlx_pixel_put(&vars->img, x, y, color);
	// while (y < y1)
	// {
	// 		printf("%d is y\n %d is y1\n %d is color\n", y, y1, color);
	// 	//printf("in\n");
	// 	my_mlx_pixel_put(&vars->img, x, y, color);
	// 	y++;
	// }
}
int	keyk_hook(int keycode, t_vars *vars)
{
	//keycode : 119 lettre W(haut)
	//keycode : 97 lettre A(gauche)
	//keycode : 115 lettre S(bas)
	//keycode : 100 lettre D(droite)
	//keycode : 65361 fleche gauche
	//keycode : 65363 fleche droite
	//printf("%d\n", keycode);

	if (keycode == 65361)
    {
      double oldDirX = vars->rc.dir.x;
      vars->rc.dir.x = vars->rc.dir.x * cos(5) - vars->rc.dir.y * sin(5);
      vars->rc.dir.y = oldDirX * sin(5) + vars->rc.dir.y * cos(5);
      double oldPlaneX = vars->rc.plane.x;
      vars->rc.plane.x = vars->rc.plane.x * cos(5) - vars->rc.plane.y * sin(5);
      vars->rc.plane.y = oldPlaneX * sin(5) + vars->rc.plane.y * cos(5);
    }
	if (keycode == 65363)
	{
      double oldDirX = vars->rc.dir.x;
      vars->rc.dir.x = vars->rc.dir.x * cos(-5) - vars->rc.dir.y * sin(-5);
      vars->rc.dir.y = oldDirX * sin(-5) + vars->rc.dir.y * cos(-5);
      double oldPlaneX = vars->rc.plane.x;
      vars->rc.plane.x = vars->rc.plane.x * cos(-5) - vars->rc.plane.y * sin(-5);
      vars->rc.plane.y = oldPlaneX * sin(-5) + vars->rc.plane.y * cos(-5);
	}
	if (keycode == 119)
    {
	  if(inttoint(vars, (int)(vars->rc.pos.x + vars->rc.dir.x * 5), (int)(vars->rc.pos.y)) == 0) 
	  	vars->rc.pos.x += vars->rc.dir.x * 5;
      if(inttoint(vars, (int)(vars->rc.pos.x), (int)(vars->rc.pos.y + vars->rc.dir.y * 5)) == 0)
	  	vars->rc.pos.y += vars->rc.dir.y * 5;
    }
	if (keycode == 97)
    {
      if(inttoint(vars, (int)(vars->rc.pos.y + vars->rc.dir.y * 5), (int)(vars->rc.pos.x)) == 0) 
	  	vars->rc.pos.y += vars->rc.dir.y * 5;
      if(inttoint(vars, (int)(vars->rc.pos.y), (int)(vars->rc.pos.x + vars->rc.dir.x * 5)) == 0)
	  	vars->rc.pos.x += vars->rc.dir.x * 5;
    }
	if (keycode == 115)
    {
      if(inttoint(vars, (int)(vars->rc.pos.x - vars->rc.dir.x * 5), (int)(vars->rc.pos.y)) == 0)
	  	vars->rc.pos.x -= vars->rc.dir.x * 5;
      if(inttoint(vars, (int)(vars->rc.pos.x), (int)(vars->rc.pos.y - vars->rc.dir.y * 5)) == 0)
	  	vars->rc.pos.y -= vars->rc.dir.y * 5;
    }
	if (keycode == 100)
    {
      if(inttoint(vars, (int)(vars->rc.pos.y - vars->rc.dir.y * 5), (int)(vars->rc.pos.x)) == 0) 
	  	vars->rc.pos.y -= vars->rc.dir.y * 5;
      if(inttoint(vars, (int)(vars->rc.pos.y), (int)(vars->rc.pos.x - vars->rc.dir.x * 5)) == 0)
	  	vars->rc.pos.x -= vars->rc.dir.x * 5;
    }
	return (0);
}


int calculate(void *vars)
{
	t_vars *v_cast = (t_vars *)vars;
	
	v_cast->rc.pos.x = 22;
    v_cast->rc.pos.y = 12;
    v_cast->rc.dir.x = 0;
    v_cast->rc.dir.y = -1;
    v_cast->rc.plane.x = 0;//v_cast->rc.dir.x;
    v_cast->rc.plane.y = 0.66;//v_cast->rc.dir.y;
	
	mlx_destroy_image(v_cast->mlx, v_cast->img.img);
	v_cast->img.img = mlx_new_image(v_cast->mlx, 1920, 1080);
	v_cast->img.addr = mlx_get_data_addr(v_cast->img.img, \
	&v_cast->img.bits_per_pixel, &v_cast->img.line_length, &v_cast->img.endian);
    // printf("ok\n");
		int x = -1;
		while (x++ < WIDTH)
		{
			v_cast->rc.camplanex = 2 * x / (double)WIDTH - 1;
			v_cast->rc.raydir.x = v_cast->rc.dir.x + v_cast->rc.plane.x * v_cast->rc.camplanex;
			v_cast->rc.raydir.y = v_cast->rc.dir.y + v_cast->rc.plane.y * v_cast->rc.camplanex;
			v_cast->rc.map.x = (int)v_cast->rc.pos.x;
			v_cast->rc.map.y = (int)v_cast->rc.pos.y;
			if (v_cast->rc.raydir.x == 0) 
				v_cast->rc.deltadist.x = 1e30;
			else
				v_cast->rc.deltadist.x = fabs(1 / v_cast->rc.raydir.x);
			if (v_cast->rc.raydir.y == 0)
				v_cast->rc.deltadist.y = 1e30;
			else
				v_cast->rc.deltadist.y = fabs(1 / v_cast->rc.raydir.y);
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
				if (inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y) > 0) 
					hit = 1;
			}
			// printf("\nok\n");

			if(side == 0) 
				perpWallDist = (v_cast->rc.sidedist.x - v_cast->rc.deltadist.x);
			else
				perpWallDist = (v_cast->rc.sidedist.y - v_cast->rc.deltadist.y);
			
			int lineHeight = (HEIGHT / perpWallDist);
			int drawStart = -lineHeight / 2 + HEIGHT / 2;
			int drawEnd = lineHeight / 2 + HEIGHT / 2;
		//	printf("drawstart : %d\ndrawend : %d\n", drawStart, drawEnd);
			if(drawStart < 0)
				drawStart = 0;
			if(drawEnd >= HEIGHT)
				drawEnd = HEIGHT - 1;
			
			int color;
			if (inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y) == 1)
			{
	//			printf("enter\n");
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
		//	printf("\n%d\n", x);
			drawline(x, drawStart, drawEnd, color, v_cast);
//			printf("ici\n");
    	}
  return (0);
}


int main(int argc, char **argv)
{
	t_vars	vars;
    
	if (argc != 2)
        return (1);
    if (parsing(&vars, argv[1]) != 0)
		return (1);
	vars.map = save_map(vars.filecub);
	vars.setmap = set_map(vars.filecub);
	vars.line_map = line_map(vars.filecub);
	vars.final_tab = final_tab(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_cross, &vars);
	mlx_key_hook(vars.win, keyk_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, 10, 10);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_loop_hook(vars.mlx, calculate, (void *)&vars);
	mlx_loop(vars.mlx);
}

void    rotate(t_pos *plane, double angle)
{
    double  tmpx;
    double  tmpy;
    
    tmpx = plane->x;
    tmpy = plane->y;
    plane->x = tmpx * cos(angle) - tmpy * sin(angle);
    plane->y = tmpx * cos(angle) + tmpy * sin(angle);
}

// int main()
// {

//     t_rc   rc;
    
//     rc.pos.x = 2;
//     rc.pos.y = 2;
//     rc.dir.x = 0;
//     rc.dir.y = -1;
//     rc.plane.x = rc.dir.x;
//     rc.plane.y = rc.dir.y;
    
//     rotate(&rc.plane, PI / 2);
//     return (0);
// }
