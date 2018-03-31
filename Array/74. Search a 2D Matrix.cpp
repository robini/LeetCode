class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].size() == 0)
			return false;
		int n = matrix[0].size();
		int low = 0;
		int high = matrix.size()*n - 1;
		while (low<high)
		{
			int mid = low + (high - low) / 2;
			if (matrix[mid / n][mid - (mid / n)*n]<target)
				low = mid + 1;
			else
				high = mid;

		}
		if (target == matrix[high / n][high - (high / n)*n])
			return true;
		return false;
	}
};