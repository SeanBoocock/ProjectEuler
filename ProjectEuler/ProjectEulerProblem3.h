#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

#include "ProjectEulerProblem.h"

class ProjectEulerProblem3 : ProjectEulerProblem<3>
{
	bool hasPrimeFactor(const uint64_t source, uint64_t& factor) const
	{
		for (auto i = 2; i < source; ++i)
		{
			if (source % i == 0)
			{
				factor = i;
				return true;
			}
		}

		return false;
	}

	virtual void ExecuteProblem() final
	{
		const auto source = 600851475143ull;
		auto remainder = source;
		auto factor = 1ull;
		std::vector<uint64_t> primeFactors;

		do
		{
			remainder /= factor;
			auto it = primeFactors.begin();
			for (auto endIt = primeFactors.end(); it != endIt; ++it)
			{
				if (*it < factor)
				{
					break;
				}
			}

			primeFactors.insert(it, factor);

		} while (hasPrimeFactor(remainder, factor));

		std::cout << "Largest prime factor is " << (remainder > primeFactors.front() ? remainder : primeFactors.front());
	}
} g_problem3;