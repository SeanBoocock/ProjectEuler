#pragma once

#include <unordered_map>

#include "ProjectEulerProblem.h"

//The following iterative sequence is defined for the set of positive integers :
//
//n -> n / 2 (n is even)
//n -> 3n + 1 (n is odd)
//
//Using the rule above and starting with 13, we generate the following sequence :
//
//13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
//It can be seen that this sequence(starting at 13 and finishing at 1) contains 10 terms.Although it has not been proved yet(Collatz Problem), it is thought that all starting numbers finish at 1.
//
//Which starting number, under one million, produces the longest chain ?
//
//NOTE : Once the chain starts the terms are allowed to go above one million.

class ProjectEulerProblem14 : ProjectEulerProblem<14>
{
	typedef std::unordered_map<uint32_t, uint32_t> CacheMap;
	struct Chain { uint32_t start = 0; uint32_t count = 0; };

	uint32_t CalculateChainLength(CacheMap& cachedResults, const uint32_t chainStart)
	{
		auto findIt = cachedResults.find(chainStart);
		if (findIt != cachedResults.end())
		{
			return findIt->second;
		}
		else
		{
			uint32_t newChainStart = chainStart;
			if ((newChainStart % 2) == 0)
			{
				newChainStart /= 2;
			}
			else
			{
				newChainStart = (3 * newChainStart) + 1;
			}

			auto insertIt = cachedResults.insert(std::make_pair(chainStart, CalculateChainLength(cachedResults, newChainStart) + 1));
			return insertIt.first->second;
		}
	}

	virtual void ExecuteProblem() final
	{
		static const uint32_t chainStartMax = 1000000;
		CacheMap cachedResults = { {1, 1}, {2, 2} };
		Chain longestChain;
		for (uint32_t chainStart = 3; chainStart <= chainStartMax; ++chainStart)
		{
			const uint32_t chainLength = CalculateChainLength(cachedResults, chainStart);
			if (chainLength > longestChain.count)
			{
				longestChain.count = chainLength;
				longestChain.start = chainStart;
			}
		}
		
		std::cout << "The starting number, under one million, that produces the longest chain is " << longestChain.start;
	}
} g_problem14;