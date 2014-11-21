#pragma once

#include "ProjectEulerProblem.h"


//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10 001st prime number ?
class ProjectEulerProblem7 : ProjectEulerProblem<7>
{
	virtual void ExecuteProblem() final
	{
		typedef std::array<uint64_t, 10001> FactorArray;
		FactorArray primeFactors = { 2,3 };
		for (FactorArray::size_type newPrimeIndex = 2; newPrimeIndex < 10001; ++newPrimeIndex)
		{
			for (uint64_t potentialPrime = primeFactors[newPrimeIndex-1]; ; potentialPrime += 2)
			{
				bool isPrime = true;
				for (FactorArray::size_type oldPrimeIndex = 0; oldPrimeIndex < newPrimeIndex && isPrime; ++oldPrimeIndex)
				{
					isPrime = (potentialPrime % primeFactors[oldPrimeIndex]) != 0;
				}

				if (isPrime)
				{
					primeFactors[newPrimeIndex] = potentialPrime;
					break;
				}
			}
		}
		std::cout << "The 10,001st prime number is " << primeFactors[10000];
	}
} g_problem7;