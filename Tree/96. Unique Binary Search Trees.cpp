class Solution {
public:
	void helper(vector<int>& helpers, int& cur, int n)
	{
		if (cur == 0 || cur == 1)
		{
			helpers.push_back(1);
		}
		else
		{
			int res = 0;
			int i = 0;
			int j = cur - 1;
			for (;j >= 0;i++, j--)
			{
				res += helpers[i] * helpers[j];
			}
			helpers.push_back(res);
		}
		if (++cur <= n)
			helper(helpers, cur, n);

	}
	int numTrees(int n) {
		/*if(n==0||n==1)
		return 1;


		int res = 0;
		int i = 0;
		int j = n-1;
		for(;j>=0;i++,j--)
		{
		res += numTrees(i)*numTrees(j);
		}*/
		vector<int> helpers;
		int cur = 0;
		helper(helpers, cur, n);
		return helpers[helpers.size() - 1];

	}
};