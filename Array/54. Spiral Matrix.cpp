class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty())
			return res;
		int m = matrix.size();
		int n = matrix[0].size();
		int circle = min(m, n) / 2;
		for (int i = 0;i<circle;++i)
		{
			for (int j = i;j<n - 1 - i;++j)
				res.push_back(matrix[i][j]);
			for (int j = i;j<m - i - 1;++j)
				res.push_back(matrix[j][n - 1 - i]);
			for (int j = n - 1 - i;j>i;--j)
				res.push_back(matrix[m - 1 - i][j]);
			for (int j = m - 1 - i;j>i;--j)
				res.push_back(matrix[j][i]);
		}
		if (min(m, n) % 2 == 1)
		{
			if (min(m, n) == m)
				for (int i = m / 2;i<n - m / 2;++i)
					res.push_back(matrix[m / 2][i]);
			else
				for (int i = n / 2;i<m - n / 2;++i)
					res.push_back(matrix[i][n / 2]);
		}

		return res;
	}
};