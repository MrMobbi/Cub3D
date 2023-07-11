
#include "cub3d.h"

t_real	ft_next_wall_se(float facing, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	angle;

	angle = facing;							// angle is 0 to 90
	distance.y = (int)pos.y + 1 - pos.y;	// go + in y
	distance.x = (int)pos.x + 1 - pos.x;	// go + in x
	
	printf("distance y[%f]\n", distance.y);
	printf("distance x[%f]\n", distance.x);
	printf("angle [%f]\n", angle);

	hypo.y = distance.y / sin(angle);
	hypo.x = distance.x / cos(angle);
	printf("hypo y[%f]\n", hypo.y);
	printf("hypo x[%f]\n", hypo.x);

	if (hypo.y < hypo.x)
	{
		printf("Hypo_y SE\n");
		wall.y = pos.y + distance.y;
		wall.x = pos.x + (distance.y / tan(angle));
		if (map[(int)pos.y + 1][(int)pos.x] != '1')
			wall = ft_next_wall_se(facing, wall, map);
	}
	else if (hypo.x < hypo.y)
	{
		printf("Hypo_x SE\n");
		wall.y = pos.y + (distance.x * tan(angle));
		wall.x = pos.x + distance.x;
		if (map[(int)pos.y][(int)pos.x + 1] != '1')
			wall = ft_next_wall_se(facing, wall, map);
		
	}
	printf("wall y[%f]\n", wall.y);
	printf("wall x[%f]\n", wall.x);
	return (wall);
}

t_real	ft_next_wall_sw(float facing, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	angle;

	angle = M_PI - facing;					// angle is 90 to 180
	distance.y = (int)pos.y + 1 - pos.y;	// go + in y
	distance.x = pos.x - (int)pos.x;		// go - in x
	if (distance.x == 0)
		distance.x = pos.x - 1;
	
	printf("distance y[%f]\n", distance.y);
	printf("distance x[%f]\n", distance.x);
	printf("pos y[%f]\n", pos.y);
	printf("pos x[%f]\n", pos.x);
	printf("angle [%f]\n", angle);

	hypo.y = distance.y / sin(angle);
	hypo.x = distance.x / cos(angle);
	printf("hypo y[%f]\n", hypo.y);
	printf("hypo x[%f]\n", hypo.x);

	if (hypo.y < hypo.x)
	{
		printf("Hypo_y SW\n");
		wall.y = pos.y + distance.y;
		wall.x = pos.x - (distance.y / tan(angle));
		if (map[(int)pos.y + 1][(int)pos.x] != '1')
			wall = ft_next_wall_sw(facing, wall, map);
	}
	else if (hypo.x < hypo.y)
	{
		printf("Hypo_x SW\n");
		wall.y = pos.y + (distance.x * tan(angle));
		wall.x = pos.x - distance.x;
		if (map[(int)pos.y][(int)pos.x - 1] != '1')
			wall = ft_next_wall_sw(facing, wall, map);
	}
	printf("wall y[%f]\n", wall.y);
	printf("wall x[%f]\n", wall.x);
	return (wall);
}

t_real	ft_next_wall_nw(float facing, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	angle;

	angle = facing - M_PI;				// angle is 180 to 270
	distance.y = pos.y - (int)pos.y;	// go - in y
	distance.x = pos.x - (int)pos.x;	// go - in x
	if (distance.y == 0)
		distance.y = pos.y - 1;
	if (distance.x == 0)
		distance.x = pos.x - 1;
	
	printf("distance y[%f]\n", distance.y);
	printf("distance x[%f]\n", distance.x);
	printf("angle [%f]\n", angle);

	hypo.y = distance.y / sin(angle);
	hypo.x = distance.x / cos(angle);
	printf("hypo y[%f]\n", hypo.y);
	printf("hypo x[%f]\n", hypo.x);

	if (hypo.y < hypo.x)
	{
		printf("Hypo_y NW\n");
		wall.y = pos.y - distance.y;
		wall.x = pos.x - (distance.y / tan(angle));
		if (map[(int)pos.y - 1][(int)pos.x] != '1')
			wall = ft_next_wall_nw(facing, wall, map);
	}
	else
	{
		printf("Hypo_x NW\n");
		wall.y = pos.y - (distance.x * tan(angle));
		wall.x = pos.x - distance.x;
		if (map[(int)pos.y][(int)pos.x - 1] != '1')
			wall = ft_next_wall_nw(facing, wall, map);
		
	}
	printf("wall y[%f]\n", wall.y);
	printf("wall x[%f]\n", wall.x);
	return (wall);
}

t_real	ft_next_wall_ne(float facing, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	angle;

	angle = (2 * M_PI) - facing;			// angle is 270 to 360
	distance.y = pos.y - (int)pos.y;		// go - in y
	distance.x = (int)pos.x + 1 - pos.x;	// go + in x
	if (distance.y == 0)
		distance.y = pos.y - 1;
	
	printf("distance y[%f]\n", distance.y);
	printf("distance x[%f]\n", distance.x);
	printf("angle [%f]\n", angle);

	hypo.y = distance.y / sin(angle);
	hypo.x = distance.x / cos(angle);
	printf("hypo y[%f]\n", hypo.y);
	printf("hypo x[%f]\n", hypo.x);

	if (hypo.y < hypo.x)
	{
		printf("Hypo_y NE\n");
		wall.y = pos.y - distance.y;
		wall.x = pos.x + (distance.y / tan(angle));
		if (map[(int)pos.y - 1][(int)pos.x] != '1')
			wall = ft_next_wall_ne(facing, wall, map);
	}
	else if (hypo.x < hypo.y)
	{
		printf("Hypo_x NE\n");
		wall.y = pos.y - (distance.x * tan(angle));
		wall.x = pos.x + distance.x;
		if (map[(int)pos.y][(int)pos.x + 1] != '1')
			wall = ft_next_wall_ne(facing, wall, map);
	}
	printf("wall y[%f]\n", wall.y);
	printf("wall x[%f]\n", wall.x);
	return (wall);
}
/*
static float	ft_angle_to_rad(int angle)
{
	float	rad;

	rad = 0;
	return (rad);
}
*/
static int	ft_rad_to_angle(float facing)
{
	int	angle;
	
	angle = (int)((360 / (2 * M_PI)) * facing);
	return (angle);
}

static float	get_max(float step_x, float step_y)
{
	float	abs_step_x;
	float	abs_step_y;
	float	max;

	if (step_x < 0)
		abs_step_x = -step_x;
	else
		abs_step_x = step_x;
	if (step_y < 0)
		abs_step_y = -step_y;
	else
		abs_step_y = step_y;
	if (abs_step_x > abs_step_y)
		max = abs_step_x;
	else
		max = abs_step_y;
	return (max);
}

static void	ft_draw_ray(t_cube *cube, t_real *wall, t_rgb *color)
{
	float	step_x;
	float	step_y;
	float	max;
	t_real	a;
	t_real	b;
	float	ratio_x;
	float	ratio_y;

	ratio_x = ((float)WIN_WIDTH / 2) / cube->map_max_x;
	ratio_y = (float)WIN_HEIGHT / cube->map_max_y;

	a.x = cube->player->real->x * ratio_x;
	a.y = cube->player->real->y * ratio_y;
	b.x = wall->x * ratio_x;
	b.y = wall->y * ratio_y;
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = get_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		ft_mlx_pixel_put(cube->img, a.x, a.y, ft_encode_rgb(color->r, color->g, color->b));
		a.x += step_x;
		a.y += step_y;
	}
}

void	ft_print_ray_v2(t_cube *cube, float facing)
{
	t_real	wall;
	t_rgb	color;
	int		angle;

	color.r = 0;
	color.g = 0;
	color.b = 255;
	angle = ft_rad_to_angle(facing);
	printf("angle [%d]\n", angle);
	if (angle == 0)
	{
	//	wall = ft_next_wall_e(facing, *cube->player->real, cube->map);
		printf("Looking East\n");
	}
	else if (angle == 90)
	{
	//	wall = ft_next_wall_s(facing, *cube->player->real, cube->map);
		printf("Looking South\n");
	}
	else if (angle == 180)
	{
	//	wall = ft_next_wall_w(facing, *cube->player->real, cube->map);
		printf("Looking West\n");
	}
	else if (angle == 270)
	{
	//	wall = ft_next_wall_n(facing, *cube->player->real, cube->map);
		printf("Looking North\n");
	}
	else if (angle > 0 && angle < 90)
	{
		wall = ft_next_wall_se(facing, *cube->player->real, cube->map);
		printf("Looking South East\n");
	}
	else if (angle > 90 && angle < 180)
	{
		wall = ft_next_wall_sw(facing, *cube->player->real, cube->map);
		printf("Looking South West\n");
	}
	else if (angle > 180 && angle < 270)
	{
		wall = ft_next_wall_nw(facing, *cube->player->real, cube->map);
		printf("Looking North West\n");
	}
	else if (angle > 270 && angle <= 359)
	{
		wall = ft_next_wall_ne(facing, *cube->player->real, cube->map);
		printf("Looking North East\n");
	}
	ft_draw_cube(cube, &wall, 0.05, &color);
	ft_draw_ray(cube, &wall, &color);
}
