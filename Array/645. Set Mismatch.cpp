class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> res;
		for (int n : nums)
		{
			int& t = nums[abs(n) - 1];
			if (t>0)
				t = -t;
			else
				res.push_back(abs(n));
		}
		for (auto it = nums.begin();it != nums.end();++it)
			if (*it>0)
				res.push_back(it - nums.begin() + 1);
		return res;
	}
};