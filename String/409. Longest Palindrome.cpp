class Solution {
public:
	int longestPalindrome(string s) {
		map<char, int> m;
		int len = s.length();
		for (int i = 0;i<len;i++)
		{
			m[s[i]]++;
		}
		int odds = 0;
		for (auto it = m.begin();it != m.end();++it)
		{
			odds += it->second & 1;
		}
		return len - odds + (odds>0);
	}
};