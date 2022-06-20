/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vecteur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:51:04 by avaures           #+#    #+#             */
/*   Updated: 2022/06/20 18:46:41 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define PI 3.1415926535
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
		printf("la");
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