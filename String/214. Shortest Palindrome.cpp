class Solution {
public:
	string shortestPalindrome(string s) {
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		string l = s + "#" + rev_s;
		int n = l.size();
		vector<int> next(n, 0);
		int k = -1;
		next[0] = -1;
		for (int i = 1;i<n;++i)
		{
			while (k>-1 && l[k + 1] != l[i])
				k = next[k];
			if (l[k + 1] == l[i])
				++k;
			next[i] = k;
		}
		return rev_s.substr(0, rev_s.size() - 1 - next[n - 1]) + s;
	}
};