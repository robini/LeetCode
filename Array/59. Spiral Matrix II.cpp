class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0)
			return vector<vector<int>>{};
		vector<vector<int>> res(n, vector<int>(n));
		int num = 0;
		for (int i = 0;i<n / 2;++i)
		{
			int k = n - 1 - i;
			for (int j = i;j<k;++j)
				res[i][j] = ++num;
			for (int j = i;j<k;++j)
				res[j][k] = ++num;
			for (int j = k;j>i;--j)
				res[k][j] = ++num;
			for (int j = k;j>i;--j)
				res[j][i] = ++num;
		}
		if (n % 2 == 1)
			res[n / 2][n / 2] = ++num;
		return res;
	}
};