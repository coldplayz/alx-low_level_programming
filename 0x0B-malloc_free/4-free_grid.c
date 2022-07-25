#include <stdlib.h>
#include "main.h"

/**
 * free_grid - de-allocates the matrix pointed to by grid
 * @grid: pointer to a 2D array
 * @height: the number of rows in the grid
 */
void free_grid(int **grid, int height)
{
	(void)height;

	free(grid);
}
