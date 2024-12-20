bool binary(unsigned long long A[], unsigned long long low, unsigned long long high, unsigned long long key)
{
	unsigned long long mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (A[mid] == key) return true;
		else if (A[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
	return false;
}