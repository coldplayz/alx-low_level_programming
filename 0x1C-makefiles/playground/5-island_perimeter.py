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
    num_land_zones = 0
    perimeter = 0

    for i in range(grid_len):  # i represents row number
        for j in range(row_len):  # j represents column number
            square = grid[i][j]
            if square == 1:  # square is a land zone
                # Check if the square is horizontally or vertically connected
                if i != 0 and grid[i - 1][j] == 1:  # check top square
                    num_land_zones += 1
                elif i != (grid_len - 1) and grid[i + 1][j] == 1:  # bottom sq
                    num_land_zones += 1
                elif j != 0 and grid[i][j - 1] == 1: # check left square
                    num_land_zones += 1
                elif j != (row_len - 1) and grid[i][j + 1]:  # check right sq
                    num_land_zones += 1

    perimeter = (1 * 2) + (num_land_zones * 2)  # formula for perimeter of rec

    return perimeter
