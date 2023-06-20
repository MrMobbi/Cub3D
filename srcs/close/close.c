
#include "cub3d.h"

/**
 * Close the program
 * @param cube
 *
 * @return int
 */
int	ft_close(t_cube *cube)
{
//	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	free(cube->matrix);
	free(cube->path_wall_n);
	free(cube->path_wall_s);
	free(cube->path_wall_w);
	free(cube->path_wall_e);
	free(cube->floor);
	free(cube->ceiling);
	free(cube);
	ft_print_success(MSG_CLOSE_SUCCESS);
	return (0);
}
