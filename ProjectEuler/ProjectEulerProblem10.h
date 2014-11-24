#pragma once

#include <memory>

#include "ProjectEulerProblem.h"


//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

//Find the sum of all the primes below two million.
class ProjectEulerProblem10 : ProjectEulerProblem<10>
{
	virtual void ExecuteProblem() final
	{
		auto primeFactorsHolder = std::unique_ptr<uint64_t>(new uint64_t[200000]);
		auto primeFactors = primeFactorsHolder.get();
		primeFactors[0] = 2;
		primeFactors[1] = 3;
		uint64_t sum = 2;
		uint64_t newPrimeIndex = 2;
		do
		{
			sum += primeFactors[newPrimeIndex - 1];
			for (uint64_t potentialPrime = primeFactors[newPrimeIndex - 1]; ; potentialPrime += 2)
			{
				bool isPrime = true;
				for (uint64_t oldPrimeIndex = 0; oldPrimeIndex < newPrimeIndex && isPrime; ++oldPrimeIndex)
				{
					isPrime = (potentialPrime % primeFactors[oldPrimeIndex]) != 0;
				}

				if (isPrime)
				{
					primeFactors[newPrimeIndex] = potentialPrime;
					break;
				}
			}
		} while (primeFactors[newPrimeIndex++] < 2000000);

		std::cout << "The sum of all the primes below two million is " << sum;
	}
} g_problem10;