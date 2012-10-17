/****** Miller Rabin ******/

int gcd (int a, int b) {
	return a ? gcd (b%a, a) : b;
}

int powmod (int a, int b, int m) {
	int res = 1;
	while (b)
		if (b & 1)
			res = (res * 1ll * a) % m,  --b;
		else
			a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}

bool miller_rabin (int n, int b) {
	for (int g; (g = gcd (n, b)) != 1; ++b)
		if (n > g)
			return false;
	int p=0, q=n-1;
	while ((q & 1) == 0)
		++p,  q >>= 1;
	int rem = powmod (b, q, n);
	if (rem == 1 || rem == n-1)
		return true;
	for (int i=1; i<p; ++i) {
		rem = (rem * 1ll * rem) % n;
		if (rem == n-1)  return true;
	}
	return false;
}

bool isPrime(int x)
{
  return (miller_rabin(x, 2) && miller_rabin(x, 3) && miller_rabin(x, 5));
}

/****** Miller Rabin ******/
