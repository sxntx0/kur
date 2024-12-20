bool lenear(unsigned long long A[], unsigned long long len, unsigned long long key)
{
	unsigned long long i = 0;
	while (i < len)
	{
		if (A[i++] == key) return true;
	}
	return false;
}