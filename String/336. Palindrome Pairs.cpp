class Solution {
public:

	bool isPalindrome(string str)
	{
		int n = str.size();
		int i = 0;
		int j = n - 1;
		while (i<j)
		{
			if (str[i] != str[j])
				break;
			++i;--j;
		}
		if (i >= j)
			return true;
		return false;
	}
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> res;
		int n = words.size();
		vector<int> pal;
		for (int i = 0; i < n; i++)
		{
			if (!words[i].empty() && isPalindrome(words[i]))
				pal.push_back(i);
		}
		for (int i = 0; i < n; i++)
		{
			if (words[i].empty())
				for (int j = 0;j<pal.size();++j)
				{
					res.push_back({ i,pal[j] });
					res.push_back({ pal[j],i });
				}
		}
		for (int i = 0; i < n; i++)
		{
			int ilen = words[i].size();
			if (ilen == 0)
				continue;
			for (int j = 0; j < n; j++)
			{
				int jlen = words[j].size();
				if (j == i || jlen == 0)
					continue;
				int a = 0;
				int b = jlen - 1;
				for (;a<ilen&&b >= 0;++a, --b)
				{
					if (words[i][a] != words[j][b])
						break;
				}
				if (a == ilen&&b<0)
					res.push_back({ i,j });
				else if (a == ilen&&isPalindrome(words[j].substr(0, b + 1)))
				{
					res.push_back({ i,j });
				}
				else if (b<0 && isPalindrome(words[i].substr(a, ilen - a + 1)))
				{
					res.push_back({ i,j });
				}
			}
		}
		return res;
	}
};