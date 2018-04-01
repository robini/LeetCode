class Solution {
public:
	bool isValid(string& s, int i, int j)
	{
		while (++i<--j)
		{
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	bool validPalindrome(string s) {
		int i = -1;
		int j = s.size();
		while (++i<--j)
		{
			if (s[i] != s[j])
				return isValid(s, i, j + 1) || isValid(s, i - 1, j);
		}
		return true;
	}
};