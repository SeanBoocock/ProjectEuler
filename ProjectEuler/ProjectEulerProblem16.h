#pragma once

#include "ProjectEulerProblem.h"

#include <array>

//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

//What is the sum of the digits of the number 2^1000 ?
class ProjectEulerProblem16 : ProjectEulerProblem<16>
{
	// In order to make this tractable, I do long multiplication storing the digits in base 10 in separate
	// entries in an array
	virtual void ExecuteProblem() final
	{
		typedef std::array<uint8_t, 1000> DigitsArray;
		DigitsArray digits{0};
		digits[0] = 1;
		DigitsArray::size_type lastFilledIndex = 0;

		for (uint64_t power = 0; power < 1000; ++power)
		{
			uint8_t carry = 0;
			for (DigitsArray::size_type digitIndex = 0; digitIndex <= lastFilledIndex || carry != 0; ++digitIndex)
			{
				if (digitIndex > lastFilledIndex)
				{
					lastFilledIndex = digitIndex;
				}
				
				digits[digitIndex] = (2 * digits[digitIndex]) + carry;
				if (digits[digitIndex] >= 10)
				{
					digits[digitIndex] -= 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
			}
		}

		uint64_t sum = 0;
		for (auto digit : digits)
		{
			sum += digit;
		}

		std::cout << "The sum of the digits of the number 2^1000 is " << sum;
	}
} g_problem16;