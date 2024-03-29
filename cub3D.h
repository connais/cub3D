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

#define PI		3.14159265359
#define WIDTH   1920
#define HEIGHT  1080
#define STEP	0.12
// #define CEILINGCOLOR	0x2020A9
// #define	FLOORCOLOR		0x20A920

typedef struct  s_posi
{
    int x;
    int y;
}               t_posi;

typedef struct  s_pos
{
    double x;
    double y;
}               t_pos;

typedef struct	s_rc
{
    t_pos   pos;
    t_pos   dir;
    t_pos   plane;
    t_pos   raydir;
	t_pos	sidedist;
	t_pos	deltadist;
    t_posi	map;
	t_posi	step;
	double  camplanex;
	double perpWallDist;
	int lineHeight;
	double 	wallX;
	int 	texX;
	double 	stage;
	double 	texPos;
}               t_rc;

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
	int		width;
	int		height;
	int	endian;
}		t_data;

typedef struct    t_infos
{
    int    slope_error;
    int    slope_director;
    int    dx;
    int    dy;
    int 	x_increment;
    int    y_increment;
}                s_infos;     

typedef struct s_vars {
	void	*mlx;
	void	*win;
	float		px;
	float		py;
	float		dx;
	float		dy;
	int		plen;
	t_data	img;
	t_data	NO;
	t_data	SO;
	t_data	WE;
	t_data	EA;
	t_data	wall[4];
	char	**filecub;
	char	**map;
	int		**setmap;
	int		*final_tab;
	int		len_file;
	int		size_tab;
	int		line_map;
    float	pdx;
    float	pdy;
    float	pa;
	t_rc	rc;
	int		up;
	int		strafe_left;
	int		down;
	int		strafe_right;
	int		left;
	int		right;
	int		drawStart;
	int		drawEnd;
	int		width;
	int		height;
	int		witch;
	int hit;
	int side;
	int	CEILINGCOLOR;
	int	FLOORCOLOR;
}		t_vars;

int calculate(void *vars);
int	found_player(t_vars *vars);
void	draw_player(t_vars *v_carst);
float make_b(t_vars vars);
float make_a(t_vars vars);
void    print_vector(t_vars *vars, int keycode);
int	check_move(t_vars *vars, int keycode);
int *final_tab(t_vars *vars);
int line_map(char **foldcub);
int **set_map(char **foldcub);
int	key_hook(int keycode, t_vars *vars);
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
void    bresenham(t_vars *pack, int x1, int y1, int x2, int y2);
int		find_box(t_vars *vars, int x, int y);
int		out_map(t_vars *vars, int x, int y, int keycode);\
int		keypress(int key, t_vars *vars);
int		keyrelease(int key, t_vars *vars);
void	drawceiling(int x, int start, int end, t_vars *vars);
void	draw_wall(int x, int start, int end, t_vars *vars);
void	drawfloor(int x, int start, int end, t_vars *vars);
void	drawline(int x, int y1, int y2, t_vars *vars);
int 	inttoint(t_vars *vars, int x, int y);
t_pos	*rotate(t_pos *dir, double angle);
void	translate(t_pos *pos, t_pos *dir);
int		is_valid_move(t_vars *vars, t_pos dir, t_pos pos);
void	move(t_vars *vars, int move);
void	init_vars(t_vars *vars);
void	apply_moves(t_vars *vars);
void	plane_calc(t_vars *vars);
void	update_rc_vars(t_vars *vars);
void	start_calc(t_vars *v_cast, int x);
void	calc_dist(t_vars *v_cast);
void	calc_text(t_vars *v_cast, int x);
void	calc_side(t_vars *v_cast);
void	found_hit(t_vars *v_cast);
void	clean_all(t_vars *vars);
void 	clean_double_char(char **tab);
void 	sp_clean_double_char(char **tab, int len);
void 	where_draw(t_vars *v_cast);
void	which_walldist(t_vars *v_cast, double *perpWallDist);
void	print_text(t_vars *v_cast, int x);
void 	clean_double_int(int **tab, int line_map);

#endif
