/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:40:37 by avaures           #+#    #+#             */
/*   Updated: 2022/07/21 18:17:02 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void sp_clean_double_char(char **tab, int len)
{
    int i;
    
    i = 0;
    while (i < len - 1)
    {
        printf("%d\n", i);
        //printf("%s\n", tab[i]);
        free(tab[i]);
        i++;
    }
    printf("\n");
    free(tab);
}
void clean_double_char(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
    {
       // printf("%d\n", i);
       // printf("%s\n", tab[i]);
        free(tab[i]);
        i++;
    }
 //   printf("\n");
  //  free(tab[i]);
    free(tab);
}

void clean_double_int(int **tab, int line_map)
{
    int i;
    
    i = 0;
    while (i < line_map)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    clean_all(t_vars *vars)
{
    //printf("%d\n", vars->len_file);
    clean_double_char(vars->filecub);
    clean_double_char(vars->map);
    clean_double_int(vars->setmap, vars->line_map);
    free(vars->final_tab);
}