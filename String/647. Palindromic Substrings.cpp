class Solution {
public:

	int countSubstrings(string s) {
		int n = s.length();
		int res = n;
		for (int i = 0;i<n;++i)
		{
			int l = i - 1;
			int r = i + 1;
			while (l >= 0 && r<n&&s[l] == s[r])
			{
				--l;
				++r;
				++res;
			}
			l = i;
			r = i + 1;
			while (l >= 0 && r<n&&s[l] == s[r])
			{
				--l;
				++r;
				++res;
			}

		}

		return res;
	}
};