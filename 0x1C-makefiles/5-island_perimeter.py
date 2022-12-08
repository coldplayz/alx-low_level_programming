#!/usr/bin/python3
'''
Island perimeter module.
'''


def island_perimeter(grid):
    ''' Returns the perimeter of the island defined by grid.

    Args:
        grid (list): a list of lists of integers describing an island's area.
            - 0 represents a water zone
            - 1 represents a land zone
            - One cell is a square with side length 1
            - Grid cells are connected horizontally/vertically, not diagonally
            - Grid is rectangular, width and height don’t exceed 100
            - Grid is completely surrounded by
            water, and there is one island (or nothing).
            - The island doesn’t have “lakes” (water inside that
            isn’t connected to the water around the island).

    Returns:
        int: the island's perimeter.
    '''

    if type(grid) is not list or len(grid) == 0:
        return

    grid_len = len(grid)
    row_len = len(grid[0])
    land_present = 0
    connected = 0
    default_cell_perimeter = 4
    perimeter = 0

    for i in range(grid_len):  # i represents row number
        for j in range(row_len):  # j represents column number
            square = grid[i][j]
            if square == 1:  # square is a land zone
                land_present = 1  # for case where only one cell
                # Check if the square is horizontally or vertically connected
                if i != 0 and grid[i - 1][j] == 1:  # check top square
                    # Reduce default cell perimeter for each connected side
                    connected = 1
                    default_cell_perimeter -= 1
                if i != (grid_len - 1) and grid[i + 1][j] == 1:  # bottom sq
                    connected = 1
                    default_cell_perimeter -= 1
                if j != 0 and grid[i][j - 1] == 1: # check left square
                    connected = 1
                    default_cell_perimeter -= 1
                if j != (row_len - 1) and grid[i][j + 1] == 1:  # right sq
                    connected = 1
                    default_cell_perimeter -= 1

                if connected:
                    perimeter += default_cell_perimeter

            # Reset defaults
            default_cell_perimeter = 4
            connected = 0

    if perimeter == 0 and land_present:
        perimeter = 4

    return perimeter
