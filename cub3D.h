#ifndef CUB3D_H
#define CUB3D_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>

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
	int		px;
	int		py;
	int		plen;
	t_data	img;
}	t_vars;

void	exit_game(t_vars *vars);
int		close_cross(t_vars *vars);
int		player(void *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ftclose(int keycode, t_vars *vars);
#endif
