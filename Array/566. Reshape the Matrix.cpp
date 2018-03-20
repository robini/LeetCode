class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {//1,4
		int preR = nums.size();
		int preC = nums[0].size();
		if (preR*preC<r*c)
			return nums;
		vector<vector<int>> res;
		vector<int> row;
		int n = 0;
		for (int i = 0;i<preR;++i)
		{
			for (int j = 0;j<preC;++j)
			{
				if (n == c)
				{
					res.push_back(row);
					row.clear();
					n = 0;
				}
				row.push_back(nums[i][j]);
				++n;


			}
		}
		res.push_back(row);

		return res;
	}
};