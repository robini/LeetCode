class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int a = matrix[0].size();
		int b = matrix.size();
		for (int i = 1;i<b;i++)
			for (int j = 1;j<a;j++)
				if (matrix[i][j] != matrix[i - 1][j - 1])
					return false;

		return true;

	}
};