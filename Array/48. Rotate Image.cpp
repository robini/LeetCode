class Solution {
	void rotate(int& a, int& b, int& c, int& d)
	{
		int t = a;
		a = d;
		d = c;
		c = b;
		b = t;
	}
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0;i<n / 2;++i)
		{
			int k = n - 1 - i * 2;
			for (int j = 0;j<k;++j)
			{
				rotate(matrix[i][j + i], matrix[j + i][n - 1 - i], matrix[n - 1 - i][n - 1 - j - i], matrix[n - 1 - j - i][i]);
			}
		}



	}
};