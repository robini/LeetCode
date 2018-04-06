class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int maxLen = 1;
		int ml = 0;
		int mr = 0;
		for (int i = 0;i<n;++i)
		{
			int l = i - 1;
			int r = i + 1;
			while (l >= 0 && r<n&&s[l] == s[r])
			{
				--l;
				++r;
			}
			if (r - l - 1>maxLen)
			{
				maxLen = r - l - 1;
				ml = l + 1;
				mr = r - 1;
			}
			l = i;
			r = i + 1;
			while (l >= 0 && r<n&&s[l] == s[r])
			{
				--l;
				++r;
			}
			if (r - l - 1>maxLen)
			{
				maxLen = r - l - 1;
				ml = l + 1;
				mr = r - 1;
			}

		}

		return s.substr(ml, mr - ml + 1);
	}
};