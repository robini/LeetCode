class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for (auto it = nums.begin();it != nums.end();++it)
			if (*it <= 0 || *it>size)
				*it = 0;

		for (int i = 0;i<size;++i)
		{

			if (nums[i]>0)
			{
				int t = nums[i] - 1;
				while (nums[t]>0)
				{
					int idx = nums[t] - 1;
					nums[t] = -1;
					t = idx;
				}
				nums[t] = -1;
			}
		}

		auto it = nums.begin();
		for (;it != nums.end();++it)
			if (*it != -1)
				return (it - nums.begin() + 1);
		if (it == nums.end())
			return size + 1;
	}
};