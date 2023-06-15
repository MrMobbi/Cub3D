
#include "cub3d.h"

/**
 * Print error message and exit program
 * @param str error message
 *
 * @return void
 */
void	ft_print_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * Print success message and exit program
 * @param str success message
 *
 * @return void
 */
void	ft_print_success(char *str)
{
	printf("Success\n");
	printf("%s\n", str);
	exit(EXIT_SUCCESS);
}
