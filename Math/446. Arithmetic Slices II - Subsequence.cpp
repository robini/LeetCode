class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.empty()) return 0;
		int n = A.size();
		vector<unordered_map<long long, int>>dp(n);
		int res = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				long long d = (long long)A[i] - (long long)A[j];
				++dp[i][d];
				if (dp[j].count(d))//if(dp[j][d]!=0)
				{
					dp[i][d] += dp[j][d];
					res += dp[j][d];
				}
			}
		}
		return res;


	}
};