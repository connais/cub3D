/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:27:31 by avaures           #+#    #+#             */
/*   Updated: 2022/06/15 19:00:57 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int *final_tab(t_vars *vars)
{
    int	i;
	int	j;
    int k;
	int *res;
    vars->size_tab = 0;
    i = 0;
    k = 0;
    while (i < vars->line_map)
    {
        vars->size_tab += vars->setmap[i][0];
        i++;
    }
    res = malloc(sizeof(int) * vars->size_tab);
    if (!res)
        return (NULL);
    i = -1;
    while (++i < vars->line_map)
    {
        j = -1;
        while (++j < vars->setmap[i][0])
        {
            if (vars->map[i][j] == '1')
                res[k] = 1;            
            else if (vars->map[i][j] == '0')
                res[k] = 0;
            else if (vars->map[i][j] == ' ')
                res[k] = 1;
            k++;
        }
    }
    // k = 0;
    // i = 0;
    // j = 0;
    // while (k < vars->size_tab)
    // {
    //     if (i < vars->setmap[j][0])
    //     {
    //         printf("%d", res[k]);
    //         i++;
    //         k++;
    //     }
    //     else
    //     {
    //         i = 0;
    //         j++;
    //         printf("\n");
    //     }
    // }
    return (res);
}