class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> num(n);
		int np = primes.size();
		vector<int> p(np, 0);
		num[0] = 1;
		for (int i = 1;i<n;++i)
		{
			num[i] = num[p[0]] * primes[0];
			for (int j = 1;j<np;++j)
				if (num[i] > num[p[j]] * primes[j])
					num[i] = num[p[j]] * primes[j];
			for (int j = 0;j<np;++j)
				if (num[i] == num[p[j]] * primes[j])
					++p[j];
		}
		return num[n - 1];
	}
};