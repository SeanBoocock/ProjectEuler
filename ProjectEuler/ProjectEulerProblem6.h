#pragma once

#include "ProjectEulerProblem.h"


//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385
//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)^2 = 552 = 3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

class ProjectEulerProblem6 : ProjectEulerProblem<6>
{
	uint64_t CalculateSumDifference(uint64_t max)
	{
		uint64_t toReturn = 0;
		for (uint64_t i = 1; i <= max; ++i)
		{
			for (uint64_t j = 1; j < i; ++j)
			{
				toReturn += j * i;
			}

			for (uint64_t j = i + 1; j <= max; ++j)
			{
				toReturn += j * i;
			}
		}

		return toReturn;
	}

	virtual void ExecuteProblem() final
	{
		std::cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << CalculateSumDifference(100);
	}
} g_problem6;