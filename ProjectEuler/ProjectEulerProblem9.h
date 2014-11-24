#pragma once

#include "ProjectEulerProblem.h"


//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

//a2 + b2 = c2
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.
class ProjectEulerProblem9 : ProjectEulerProblem<9>
{
	virtual void ExecuteProblem() final
	{
		uint64_t product = 0;
		for (uint64_t a = 1; a < 1000; ++a)
		{
			for (uint64_t b = a + 1; b < 1000; ++b)
			{
				const uint64_t c = 1000 - a - b;
				if (c > a && c > b)
				{
					if ((c*c) == (a*a + b*b))
					{
						product = a * b * c;
						break;
					}
				}
			}
		}
		std::cout << "The product abc is " << product;
	}
} g_problem9;