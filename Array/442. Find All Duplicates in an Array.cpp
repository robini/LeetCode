class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		for (int i = 0;i<n;++i)
		{
			int j = abs(nums[i]);
			if (nums[j - 1]>0)
				nums[j - 1] = -nums[j - 1];
			else
				res.push_back(j);
		}

		return res;
	}
};