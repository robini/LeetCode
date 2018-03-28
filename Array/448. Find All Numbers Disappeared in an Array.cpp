class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		for (int n : nums)
		{
			if (nums[abs(n) - 1]>0)
				nums[abs(n) - 1] = -nums[abs(n) - 1];
		}
		for (auto it = nums.begin();it != nums.end();++it)
			if (*it>0)
				res.push_back(it - nums.begin() + 1);
		return res;
	}
};