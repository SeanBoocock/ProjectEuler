#include <iostream>
using namespace std;

bool isPalindrome(unsigned int toTest)
{
	unsigned int digits[6] = { 0, 0, 0, 0, 0, 0 };
	unsigned int index = 0;
	while (toTest > 0)
	{
		digits[index++] = toTest % 10;
		toTest /= 10;
	}
	
	unsigned int start = 0;
	unsigned int end = index - 1; 
	while(start < end)
	{
		if (digits[start++] != digits[end--])
		{
			return false;
		}
	}
	
	return true;
}


int main() 
{
	unsigned int largestPalindrome = 0;
	for (unsigned int i = 100; i < 1000; ++i)
	{
		for (unsigned int j = i; j < 1000; ++j)
		{
			const unsigned int candidate = i * j;
			if (candidate > largestPalindrome
				&& isPalindrome(candidate))
			{
				largestPalindrome = candidate;
			}
		}
	}
	
	cout << "Largest palindrome: " << largestPalindrome;
	return 0;
}
