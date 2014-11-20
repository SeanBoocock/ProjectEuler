#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>

#include "ProjectEulerProblem.h"

//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

class ProjectEulerProblem5 : ProjectEulerProblem<5>
{
	typedef std::array<uint64_t, 8> FactorArray;
	const FactorArray m_primesToTwenty; // = { 2, 3, 5, 7, 11, 13, 17, 19 }

public:
	ProjectEulerProblem5()
		: m_primesToTwenty(FactorArray{ 2, 3, 5, 7, 11, 13, 17, 19 })
	{}

	ProjectEulerProblem5& operator=(const ProjectEulerProblem5&) = delete;

private:
	FactorArray FindPrimeFactors(uint64_t toFactor)
	{
		FactorArray factorCountsToReturn = { 0 };
		while (toFactor > 1)
		{
			for (FactorArray::size_type i = 0, end = m_primesToTwenty.size(); i != end && m_primesToTwenty[i] <= toFactor; ++i)
			{
				const uint64_t potentialFactor = m_primesToTwenty[i];
				if ((toFactor % potentialFactor) == 0)
				{
					toFactor /= potentialFactor;
					++factorCountsToReturn[i];
				}
			}
		}
		return factorCountsToReturn;
	}

	virtual void ExecuteProblem() final
	{
		auto leastCommonPrimeFactors = FactorArray{ 0 };

		for (uint64_t i = 2; i <= 20; ++i)
		{
			FactorArray factorsForThisNumber = FindPrimeFactors(i);
			for (auto factorIt = factorsForThisNumber.begin(), leastCommonIt = leastCommonPrimeFactors.begin();
				factorIt != factorsForThisNumber.end();
				++factorIt, ++leastCommonIt)
			{
				if (*factorIt > *leastCommonIt)
				{
					*leastCommonIt = *factorIt;
				}
			}
		}

		const uint64_t result = std::inner_product(	m_primesToTwenty.cbegin(), 
													m_primesToTwenty.cend(),
													leastCommonPrimeFactors.cbegin(),
													static_cast<uint64_t>(1), 
													std::multiplies<uint64_t>(), 
													[](const uint64_t factor, const uint64_t power) { return static_cast<uint64_t>(std::pow(factor, power)); });

		std::cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is " << result;
	}
} g_problem5;