/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:57:11 by avaures           #+#    #+#             */
/*   Updated: 2022/07/20 18:55:15 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_color(t_data *img, int x, int y)
{
	char *dest;

	dest = img->addr + (y * img->line_length + x * 4);
	return (*(unsigned int *) dest);
}

void	calc_text(t_vars *v_cast, int x)
{
	double wallX;
	int texX;
      	int y;
	double step;
	double texPos;

	if (v_cast->side == 0) 
	 	wallX = v_cast->rc.pos.y + v_cast->rc.perpWallDist * v_cast->rc.raydir.y;
	else
		wallX = v_cast->rc.pos.x + v_cast->rc.perpWallDist * v_cast->rc.raydir.x;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)(v_cast->tex.width));
	if(v_cast->side == 0 && v_cast->rc.raydir.x > 0) 
		texX = v_cast->tex.width - texX - 1;
	if(v_cast->side == 1 && v_cast->rc.raydir.y < 0) 
		texX = v_cast->tex.width - texX - 1;
      step = 1.0 * v_cast->tex.height / v_cast->rc.lineHeight;
      texPos = (v_cast->drawStart - HEIGHT / 2 + v_cast->rc.lineHeight / 2) * step;
      y = v_cast->drawStart - 1;
      while (++y < v_cast->drawEnd)
	{
      	texPos += step;
	my_mlx_pixel_put(&v_cast->img, x, y, get_color(v_cast->tex.img, texX, (int)texPos));
	}
}
