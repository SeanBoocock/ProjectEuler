#pragma once

#include "ProjectEulerProblem.h"

//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used ?
//
//NOTE : Do not count spaces or hyphens.For example, 342 (three hundred and forty - two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.The use of "and" when writing out numbers is in compliance with British usage.
class ProjectEulerProblem17 : ProjectEulerProblem<17>
{
	uint64_t CalculateLetterCount(uint64_t number)
	{
		if (number == 0)
		{
			return 0;
		}
		else if (number > 0 && number < 20)
		{
			switch (number)
			{
			case 1:
				return 3; // "one"
			case 2:
				return 3; // "two"
			case 3:
				return 5; // "three"
			case 4:
				return 4; // "four"
			case 5:
				return 4; // "five"
			case 6:
				return 3; // "six"
			case 7:
				return 5; // "seven"
			case 8:
				return 5; // "eight"
			case 9:
				return 4; // "nine"
			case 10:
				return 3; // "ten"
			case 11:
				return 6; // "eleven"
			case 12:
				return 6; // "twelve"
			case 13:
				return 8; // "thirteen"
			case 14:
				return 8; // "fourteen"
			case 15:
				return 7; // "fifteen"
			case 16:
				return 7; // "sixteen"
			case 17:
				return 9; // "seventeen"
			case 18:
				return 8; // "eighteen"
			case 19:
				return 8; // "nineteen"
			}
		}
		else if (number >= 20 && number < 100)
		{
			uint64_t result = CalculateLetterCount(number % 10);
			const uint64_t tensDigit = number / 10;
			switch (tensDigit)
			{
			case 2:
				return 6 + result; // "twenty"
			case 3:
				return 6 + result; // "thirty"
			case 4:
				return 5 + result; // "forty"
			case 5:
				return 5 + result; // "fifty"
			case 6:
				return 5 + result; // "sixty"
			case 7:
				return 7 + result; // "seventy"
			case 8:
				return 6 + result; // "eighty"
			case 9:
				return 6 + result; // "ninety"
			}
		}
		else if (number >= 100 && number < 1000)
		{
			if ((number % 100) == 0)
			{
				return CalculateLetterCount(number / 100)
					+ 7; // "hundred"
			}
			else
			{
				return CalculateLetterCount(number / 100)
					+ 10 // "hundred" "and"
					+ CalculateLetterCount(number % 100);
			}
		}
		else if (number == 1000)
		{
			return 11; // one thousand
		}

		return 0;
	}

	virtual void ExecuteProblem() final
	{
		uint64_t sum = 0;
		for (uint64_t i = 1; i <= 1000; ++i)
		{
			sum += CalculateLetterCount(i);
		}

		std::cout << "The number of letters used for the numbers from 1 to 1000 (one thousand) inclusive if written out in words is " << sum;
	}
} g_problem17;