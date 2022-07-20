/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:57:11 by avaures           #+#    #+#             */
/*   Updated: 2022/07/20 17:28:48 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_text(t_vars *v_cast)
{
	//int texNum = v_cast->final_tab[inttoint(v_cast, v_cast->rc.map.x, v_cast->rc.map.y)] - 1; //1 subtracted from it so that texture 0 can be used!

			//calculate value of wallX
			// double wallX; //where exactly the wall was hit
			// if (v_cast->side == 0) 
			// 	wallX = v_cast->rc.pos.y + perpWallDist * v_cast->rc.raydir.y;
			// else
			// 	wallX = v_cast->rc.pos.x + perpWallDist * v_cast->rc.raydir.x;
			// wallX -= floor((wallX));

			// //x coordinate on the texture
			// int texX = (int)(wallX * (double)(texWidth));
			// if(v_cast->side == 0 && v_cast->rc.raydir.x > 0) texX = texWidth - texX - 1;
			// if(v_cast->side == 1 && v_cast->rc.raydir.y < 0) texX = texWidth - texX - 1;
			
}
