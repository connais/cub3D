/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:13:14 by avaures           #+#    #+#             */
/*   Updated: 2022/07/12 17:13:16 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int  ft_abs(int x)
{
    if (x >= 0)
        return (x);
    if (x < 0)
        return (-1 * x);
    return (0);
}

static s_infos    get_slope_director(s_infos data, int x1, int y1, int x2, int y2)
{
    data.dx = ft_abs(x2 - x1);
    data.dy = -ft_abs(y2 - y1);
    data.slope_director = 0;
    if (x1 < x2)
        data.x_increment = 1;
    else
        data.x_increment = -1;
    if (y1 < y2)
        data.y_increment = 1;
    else
        data.y_increment = -1;
    data.slope_error = data.dx + data.dy;
    return (data);
}

static void    init_data(s_infos *data)
{
    data->slope_director = 0;
    data->slope_error = 0;
    data->dx = 0;
    data->dy = 0;
    data->x_increment = 0;
    data->y_increment = 0;
}

static void    draw_line(t_vars *pack, s_infos *data, int x1, int y1, int x2, int y2)
{
   (void)x2;
    (void)y2;
    while (/*out_map(pack, x1 / 50, y1 / 50) == 0 &&*/ find_box(pack, x1 / 50, y1 / 50) == 0)
    {
        if (x1 < 1920 && x1 > 0 && y1 < 1080 && y1 > 0)
            my_mlx_pixel_put(&pack->img, x1, y1, 0x0013DDA2);
        data->slope_director = 2 * data->slope_error;
        if (data->slope_director >= data->dy) 
        { 
            data->slope_error += data->dy; 
            x1 += data->x_increment; 
        }
        if (data->slope_director <= data->dx) 
        { 
            data->slope_error += data->dx; 
            y1 += data->y_increment; 
        }
    }
}

void    bresenham(t_vars *pack, int x1, int y1, int x2, int y2)
{
    s_infos    data;

    init_data(&data);
    data = get_slope_director(data, x1, y1, x2, y2);
    draw_line(pack, &data, x1, y1, x2, y2);
}