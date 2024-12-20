bool interpolation(unsigned long long A[], unsigned long long len, unsigned long long key)
{
	unsigned long long low = 0, high = len - 1, pos;

	while (low < high)
	{
		if (A[low] > key || A[high] < key) return false;

		pos = low + ((key - A[low]) * (high - low)) / (A[high] - A[low]);

		if (pos < low || pos > high) return false;

		if (A[pos] == key) return true;
		else if (A[pos] < key) low = pos + 1;
		else high = pos - 1;
	}

	if (A[high] == A[low]) return A[low] == key;

	return false;
}