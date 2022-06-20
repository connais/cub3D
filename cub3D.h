#ifndef CUB3D_H
#define CUB3D_H

#include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "./get_next_line.h"

typedef struct	s_coords
{
	int x;
	int x0;
	int y;
	int y0;
	int i;
	int z;
	int	mapx;
	int	mapy;
}				t_coords;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	float		px;
	float		py;
	int		plen;
	t_data	img;
	char	**filecub;
	char	**map;
	int		**setmap;
	int		*final_tab;
	int		size_tab;
	int		line_map;
    float	pdx;
    float	pdy;
    float	pa;
}	t_vars;

float make_b(t_vars vars);
float make_m(t_vars vars);
void    print_vector(t_vars *vars, int keycode);
int	check_move(t_vars *vars, int keycode);
int *final_tab(t_vars *vars);
int line_map(char **foldcub);
int **set_map(char **foldcub);
void    draw_map(t_vars *vars);
char **save_map(char **foldcub);
int print_map(t_vars *data);
int wrong_file(char *file);
int wrong_extension(char *file);
int  lines_counter(char *file);
int check_ext(char *file);
int parsing(t_vars *data, char *file);
void	exit_game(t_vars *vars);
int		close_cross(t_vars *vars);
int		player(void *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ftclose(int keycode, t_vars *vars);
int		parsing(t_vars *data, char *file);
char	*get_next_line(int fd);
#endif
