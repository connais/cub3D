/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:27:31 by avaures           #+#    #+#             */
/*   Updated: 2022/07/12 18:34:40 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/*
NORD 2
SUD 3
EST 4
WEST 5
*/
int data_is(char c)
{
    if (c == ' ' || c == '1')
        return (1);
    if (c == '0')
        return (0);
    if (c == 'N')
        return (2);
    if (c == 'S')
        return(3);
    if (c == 'E')
        return (4);
    if (c == 'W')
        return (5);
    return (-1);
}

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
    res = ft_calloc(sizeof(int), vars->size_tab);
    if (!res)
        return (NULL);
    i = -1;
    while (++i < vars->line_map)
    {
        j = -1;
        while (++j < vars->setmap[i][0])
        {
            res[k] = data_is(vars->map[i][j]);
            k++;
        }
    }
    k = 0;
    i = 0;
    j = 0;
    while (k < vars->size_tab)
    {
        if (i < vars->setmap[j][0])
        {
            printf("%d", res[k]);
            i++;
            k++;
        }
        else
        {
            i = 0;
            j++;
            printf("\n");
        }
    }
    return (res);
}