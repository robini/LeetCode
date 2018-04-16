class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int res = 0;
		int n = A.size();
		for (int i = 0;i<n - 2;++i)
		{
			int slice = A[i + 1] - A[i];
			int len = 1;
			int j = i + 1;
			for (;j<n;++j)
			{
				if (A[j] - A[j - 1] != slice)
					break;
				++len;
			}
			if (len>2)
			{
				res += (len - 1)*(len - 2) / 2;
				i = j - 1;
			}
			if (j == n)
				break;


		}

		return res;
	}
};