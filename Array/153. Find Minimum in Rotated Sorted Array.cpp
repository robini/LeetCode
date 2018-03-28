class Solution {
public:
	int findMin(vector<int>& nums) {
		auto it = nums.begin();
		int min = *it;
		while (it != nums.end())
		{
			if (*it<min)
				min = *it;
			++it;
		}
		return min;
	}
};