#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

bool hasPrimeFactor(const uint64_t source, uint64_t& factor)
{
	for (uint64_t i = 2; i < source; ++i)
	{
		if (source % i == 0)
		{
			factor = i;
			return true;
		}
	}
	
	return false;
}

int main() {
	const uint64_t source = 600851475143u;
	vector<uint64_t> primeFactors;
	uint64_t remainder = source;
	uint64_t factor = 1;
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
	
	} while(hasPrimeFactor(remainder, factor));
	
	cout << "Largest prime factor is " << (remainder > primeFactors.front() ? remainder : primeFactors.front());
	return 0;
}
