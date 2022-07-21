/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:03:07 by avaures           #+#    #+#             */
/*   Updated: 2022/07/21 18:46:15 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_image(t_vars *vars)
{
	ft_bzero(vars->img.addr, HEIGHT * WIDTH * 4);
}

int calculate(void *vars)
{
	t_vars *v_cast = (t_vars *)vars;
	int x;

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
		which_walldist(v_cast, &v_cast->rc.perpWallDist);
	 	v_cast->rc.lineHeight = (int)(HEIGHT / v_cast->rc.perpWallDist);
		v_cast->drawStart =  -v_cast->rc.lineHeight / 2 + HEIGHT / 2;
		v_cast->drawEnd = v_cast->rc.lineHeight / 2 + HEIGHT / 2;
		where_draw(v_cast);
		drawline(x, v_cast->drawStart, v_cast->drawEnd, v_cast);
		//calc_text(v_cast, x);
    	}
	mlx_put_image_to_window(v_cast->mlx, v_cast->win, v_cast->img.img, 0, 0);
	return (0);
}
