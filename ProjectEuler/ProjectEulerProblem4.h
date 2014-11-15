#pragma once

#include <array>
#include <cstdint>
#include <iostream>

#include "ProjectEulerProblem.h"

class ProjectEulerProblem4 : ProjectEulerProblem<4>
{
	bool isPalindrome(unsigned int toTest) const
	{
		std::array<uint64_t, 6> digits = { 0ull };
		std::array<uint64_t, 6>::size_type index = 0;
		while (toTest > 0)
		{
			digits[index++] = toTest % 10;
			toTest /= 10;
		}

		decltype(index) start = 0;
		auto end = index - 1;
		while (start < end)
		{
			if (digits[start++] != digits[end--])
			{
				return false;
			}
		}

		return true;
	}


	virtual void ExecuteProblem() final
	{
		auto largestPalindrome = 0u;
		for (auto i = 100u; i < 1000; ++i)
		{
			for (auto j = i; j < 1000; ++j)
			{
				const auto candidate = i * j;
				if (candidate > largestPalindrome
					&& isPalindrome(candidate))
				{
					largestPalindrome = candidate;
				}
			}
		}

		std::cout << "Largest palindrome: " << largestPalindrome;
	}
} g_problem4;