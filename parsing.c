/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:44:09 by avaures           #+#    #+#             */
/*   Updated: 2022/06/14 16:44:12 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int print_map(t_vars *data)
{
    int i = 0;

    while (data->map[i])
    {
        printf("%s\n", data->map[i]);
        i++;
    }
    return (0);
}

int wrong_file(char *file)
{
    printf("File %s couldn't open. Check rights.\n", file);
    return (1);
}

int wrong_extension(char *file)
{
    printf("File %s is not .cub\n", file);
    return (1);
}

int  lines_counter(char *file)
{
    int  lines_nb;
    int     i;

    i = 0;
    lines_nb = 0;
    while (file[i])
    {
        if (file[i] == '\n')
            lines_nb++;
        i++;
    }
    return (lines_nb);
}

int check_ext(char *file)
{
    if (ft_strncmp((file + ft_strlen(file) - 4), ".cub", \
     ft_strlen(".cub")) != 0)
        return (1);
    return (0);
}

int parsing(t_vars *data, char *file)
{
    int fd;
    char *buffer;
    char *str;
    int l_count;

    l_count = 0;
     if (check_ext(file) == 1)
        return(wrong_extension(file));
    str = (char *)malloc(sizeof(char) * 1024);
    fd = open(file, O_RDWR);
    if (fd < 1)
        return(wrong_file(file));
    while((buffer = get_next_line(fd)))
    {
        str = ft_strjoin(str, buffer);
        free(buffer);
    }
    free(buffer);
    close(fd);
    l_count = lines_counter(str);
    data->map = (char **)malloc(sizeof(char *) * (l_count + 1));
    if (!data->map)
        perror ("Malloc : ");
    data->map = ft_split(str, '\n');
    return (0);
}

// int main(int argc, char **argv)
// {
//     t_vars data;
//     int     ret;

//     if (argc != 2)
//         return (1);
//     ret = parsing(&data, argv[1]);
//     if (ret == 0)
//         print_map(&data);
//     return (0);
// }