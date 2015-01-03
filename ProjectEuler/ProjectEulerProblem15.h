#pragma once

#include "ProjectEulerProblem.h"

#include <cstring>

//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//How many such routes are there through a 20×20 grid?
class ProjectEulerProblem15 : ProjectEulerProblem<15>
{
	// This is a nice elegant example of dynamic programming with a linear time solution.  The one special thing
	// to note is create a grid that is one larger in each dimension to simplify the inner loop; no branches.
	virtual void ExecuteProblem() final
	{
		static const int64_t gridSize = 22;
		int64_t grid[gridSize][gridSize];
		memset(grid, 0, gridSize * gridSize * sizeof(int64_t));

		grid[gridSize-2][gridSize-1] = 1;
		for (int64_t rowIndex = gridSize - 2; rowIndex >= 0; --rowIndex)
		{
			for (int64_t colIndex = gridSize - 2; colIndex >= 0; --colIndex)
			{		
				grid[rowIndex][colIndex] = grid[rowIndex + 1][colIndex] + grid[rowIndex][colIndex + 1];
			}
		}

		std::cout << "The many such routes through a 20×20 grid is " << grid[0][0];
	}
} g_problem15;