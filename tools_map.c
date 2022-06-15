/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:58:05 by avaures           #+#    #+#             */
/*   Updated: 2022/06/15 17:19:14 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int line_map(char **foldcub)
{
    int	i;
	int	line;

	line = 0;
	i = 0;
	while (foldcub[i])
	{
		if (foldcub[i][0] == '1' || foldcub[i][0] == ' ')
		{
			while(foldcub[i])
			{
				line++;
				i++;
			}
		}
		if(foldcub[i])
			i++;
	}
    return (line);
}
int **set_map(char **foldcub)
{
    int	i;
	int	j;
	int	line;
	int colonne;
	int **res;
	line = 0;
	i = 0;
	j = 0;

	while (foldcub[i])
	{
		if (foldcub[i][0] == '1' || foldcub[i][0] == ' ')
		{
			while(foldcub[i])
			{
				line++;
				i++;
			}
		}
		if(foldcub[i])
			i++;
	}
	res = ft_calloc(sizeof(int *), line);
	if (!res)
		return ((int **)1);
	i = 0;
	while (foldcub[i])
	{
		if (foldcub[i][0] == '1' || foldcub[i][0] == ' ')
		{
			colonne = 0;
			while (foldcub[i][colonne])
			{
				colonne++;
			}
			res[j] = ft_calloc(sizeof(int), 1);
			if(!res[j])
				return ((int **)1);
            res[j][0] = colonne;
			j++;
		}
		i++;
	}
	return (res);
}