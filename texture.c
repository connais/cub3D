/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:57:11 by avaures           #+#    #+#             */
/*   Updated: 2022/10/05 18:28:31 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_color(t_data *img, int x, int y)
{
	char *dest;

	dest = img->addr + (y * img->line_length + x * 4);
	return (*(unsigned int *) dest);
}

void	calc_texx(t_vars *v_cast)
{
	v_cast->rc.texX = (int)(v_cast->rc.wallX * (double)(v_cast->NO.width));
	if(v_cast->side == 0 )
	{
		if(v_cast->rc.raydir.x > 0)
		{
			v_cast->rc.texX = v_cast->NO.width - v_cast->rc.texX - 1;
			v_cast->witch = 0;
		}
		else
		{
			v_cast->rc.texX = v_cast->SO.width - v_cast->rc.texX - 1;
			v_cast->witch = 1;
		}
	}
	if(v_cast->side == 1 )
	{
		if(v_cast->rc.raydir.y < 0) 
		{
			v_cast->rc.texX = v_cast->WE.width - v_cast->rc.texX - 1;
			v_cast->witch = 2;
		}
		else
		{
			v_cast->rc.texX = v_cast->EA.width - v_cast->rc.texX - 1;
			v_cast->witch = 3;
		}
	}
}

void	calc_wallhit(t_vars *v_cast)
{
	if (v_cast->side == 0) 
	 	v_cast->rc.wallX = v_cast->rc.pos.y + v_cast->rc.perpWallDist * v_cast->rc.raydir.y;
	else
		v_cast->rc.wallX = v_cast->rc.pos.x + v_cast->rc.perpWallDist * v_cast->rc.raydir.x;
	v_cast->rc.wallX -= floor((v_cast->rc.wallX));
}

void	print_text(t_vars *v_cast, int x)
{	
	int 	y;
    int		lineHeight;
	
	lineHeight = v_cast->rc.lineHeight;
	v_cast->rc.stage = (double)v_cast->wall[v_cast->witch].height / (double)v_cast->rc.lineHeight;
	//v_cast->rc.stage = (double)v_cast->NO.height / (double)v_cast->rc.lineHeight;
	v_cast->rc.texPos = ((double)lineHeight - (double)HEIGHT) / 2.0 * v_cast->rc.stage;
    v_cast->rc.texPos *= (v_cast->rc.texPos > 0);
	y = v_cast->drawStart;
    while (y < v_cast->drawEnd)
	{
      	v_cast->rc.texPos += v_cast->rc.stage;
		v_cast->rc.texPos -= (v_cast->rc.texPos > v_cast->wall[v_cast->witch].height - 1);
		my_mlx_pixel_put(&v_cast->img, x, y, get_color(&v_cast->wall[v_cast->witch], v_cast->rc.texX, (int)v_cast->rc.texPos));
		// v_cast->rc.texPos -= (v_cast->rc.texPos > v_cast->NO.height - 1);
		// my_mlx_pixel_put(&v_cast->img, x, y, get_color(&v_cast->NO, v_cast->rc.texX, (int)v_cast->rc.texPos));
		y++;
	}
}
void	calc_text(t_vars *v_cast, int x)
{
	calc_wallhit(v_cast);
	calc_texx(v_cast);
    print_text(v_cast, x);
}
