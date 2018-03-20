class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int M = matrix.size() - 1;
		if (M<0)
			return res;
		int N = matrix[0].size() - 1;
		res.push_back(matrix[0][0]);
		int L = M + N - 1;
		int k = 1;
		int a = 0, b = 0;
		for (int i = 1;i <= L;i++)
		{
			if (k>0)
			{
				b = i>N ? N : i;
				a = i - b;
			}
			else
			{
				a = i>M ? M : i;
				b = i - a;
			}
			while (a >= 0 && a <= M&&b >= 0 && b <= N)
			{
				res.push_back(matrix[a][b]);
				a = a + k;
				b = b - k;
			}
			k = -k;
		}
		if (M>0 || N>0)
			res.push_back(matrix[M][N]);
		return res;
	}
};