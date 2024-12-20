#include "Header.h"

unsigned long long max(unsigned long long a, unsigned long long b)
{
	return (a >= b) ? a : b;
}

bool exponential(unsigned long long A[], unsigned long long len, unsigned long long key)
{
	if (A[0] == key) return true;

	unsigned long long i = 1;

	while (i < len && A[i] < key) i <<= 1;

	return binary(A, i / 2, max(i, len - 1), key);
}