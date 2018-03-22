class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int N = matrix.size();
		if (N == 0)
			return 0;
		int l = matrix[0][0];
		int r = matrix[N - 1][N - 1];
		while (l<r)
		{
			int midVal = l + (r - l) / 2;
			int mid = 0;
			for (int i = 0;i<N;++i)
			{
				for (int j = 0;j<N&&matrix[i][j] <= midVal;++j)
					++mid;
			}
			if (mid<k)
				l = midVal + 1;
			else
				r = midVal;

		}


		return l;
	}
};