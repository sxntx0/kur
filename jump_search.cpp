#include <cmath>

unsigned long long min(unsigned long long a, unsigned long long b)
{
	return (a >= b) ? b : a;
}

bool jump(unsigned long long A[], unsigned long long len, unsigned long long key)
{
	unsigned long long step = sqrt(len), prev = 0;

	do
	{
		if (prev >= len) return false;
		prev += step;
	} 
	while (A[min(prev, len) - 1] < key);

	for (unsigned long long i = prev - step; i < prev; i++)
	{
		if (A[i] == key) return true;
	}
	return false;
}