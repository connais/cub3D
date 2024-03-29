/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vecteur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:51:04 by avaures           #+#    #+#             */
/*   Updated: 2022/10/05 15:29:47 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float make_b(t_vars vars)
{
	float y;
	float a;
	float x;
	float b;
	a = (vars.pdy * 5) / (vars.pdx * 5);
	x = vars.px + 5;
	y = vars.py + 5;
	b = y - (a * x);
	return (b);
	
}
float make_a(t_vars vars)
{
	float a;
	a = (vars.pdy * 5) / (vars.pdx * 5);
	return (a);
	
}
void    print_vector(t_vars *vars, int keycode)
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
}
// 	if (keycode == 119)
// 		vars->py -= 5;		
// 	if (keycode == 97)
// 	{
// 		vars->pa -= 0.1;
// 		if (vars->pa < 0)
// 		vars->pa += 2 * PI;
// 		vars->px -= 5;
// 	}
// 	if (keycode == 115)
// 		vars->py += 5;
// 	if (keycode == 100)
// 		vars->px += 5;
	
// 	//if W
// 	px += pdx;
// 	py += pdy;
// 	//if S
// 	px -= pdx;
// 	py -= pdy;