class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = nums.size();
		for (auto it = nums.begin();it != nums.end();++it)
		{
			sum += ((it - nums.begin()) - *it);
		}
		return sum;

	}
};