
#include "cub3D.h"

void	start_calc(t_vars *v_cast, int x)
{
	v_cast->rc.camplanex = 2.0 * (double)x / (double)WIDTH - 1.0;
			v_cast->rc.raydir.x = v_cast->rc.dir.x + v_cast->rc.plane.x * v_cast->rc.camplanex;
			v_cast->rc.raydir.y = v_cast->rc.dir.y + v_cast->rc.plane.y * v_cast->rc.camplanex;
			v_cast->rc.map.x = (int)v_cast->rc.pos.x;
			v_cast->rc.map.y = (int)v_cast->rc.pos.y;
}
void	calc_dist(t_vars *v_cast)
{	
	if (v_cast->rc.raydir.x <= 0.00001 && v_cast->rc.raydir.x >= -0.00001) 
		v_cast->rc.deltadist.x = 1e30;
	else
		v_cast->rc.deltadist.x = fabs(1.0 / v_cast->rc.raydir.x);
	if (v_cast->rc.raydir.y <= 0.00001 && v_cast->rc.raydir.y >= -0.00001)
		v_cast->rc.deltadist.y = 1e30;
	else
		v_cast->rc.deltadist.y = fabs(1.0 / v_cast->rc.raydir.y);
}
