/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:51:57 by avaures           #+#    #+#             */
/*   Updated: 2022/06/14 19:06:45 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **save_map(char **foldcub)
{
    int	i;
	int	j;
	int	line;
	int colonne;
	char **res;
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
	res = ft_calloc(sizeof(char *), line + 1);
	if (!res)
		return (NULL);
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
			res[j] = ft_calloc(sizeof(char), colonne + 1);
			if(!res[j])
				return (NULL);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (foldcub[i])
	{
		if (foldcub[i][0] == '1' || foldcub[i][0] == ' ')
		{
			colonne = 0;
			while (foldcub[i][colonne])
			{
				res[j][colonne] = foldcub[i][colonne];
				colonne++;
			}
			j++;
		}
		i++;
	}
	return (res);
}