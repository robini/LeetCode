class Solution {
public:
	bool isSelf(int n)
	{
		int t = n;
		while (t / 10 != 0)
		{
			if (t % 10 == 0)
				return false;
			if (n % (t % 10) != 0)
				return false;
			t = t / 10;
		}
		if (n%t != 0)
			return false;
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int i = left;i <= right;++i)
		{
			if (isSelf(i))
				res.push_back(i);
		}
		return res;
	}
};