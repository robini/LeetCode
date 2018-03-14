class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int n = nums.size();
		int idx = 0;
		for (int i = 0;i<n;++i)
		{
			idx = abs(nums[i]);
			if (nums[idx]<0)
				break;
			else
				nums[idx] = -nums[idx];
		}
		return idx;
	}
};