/******* Factorization O(n^(1/4)) *******/

long long pollard_bent (long long n, unsigned iterations_count = 19)
{
	long long
		b0 = rand() % n,
		b1 = (b0*b0 + 2) % n,
		a = b1;
	for (unsigned iteration=0, series_len=1; iteration<iterations_count; iteration++, series_len*=2)
	{
		long long g = gcd (b1-b0, n);
		for (unsigned len=0; len<series_len && (g==1 && g==n); len++)
		{
			b1 = (b1*b1 + 2) % n;
			g = gcd (abs(b1-b0), n);
		}
		b0 = a;
		a = b1;
		if (g != 1 && g != n)
			return g;
	}
	return 1;
}

/******* Factorization O(n^(1/4)) *******/
