class Solution {
public:
	int countPrimes(int n) {
		if (n<2)
			return 0;
		vector<bool> primes(n, true);
		primes[0] = false;
		primes[1] = false;
		for (int i = 2;i*i<n;++i)
		{
			if (primes[i])
			{
				for (int j = i;j*i<n;++j)
					if (primes[i*j])
						primes[i*j] = false;
			}

		}
		int count = 0;
		for (bool p : primes)
			if (p)
				++count;
		return count;
	}
};