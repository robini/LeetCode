class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> rec;
		rec[0] = 1;
		int cum = 0;
		int res = 0;
		for (int i = 0;i<nums.size();i++)
		{
			cum += nums[i];
			res += rec[cum - k];
			rec[cum]++;
		}
		return res;
	}
};