class Solution {
public:
	void fastSort(map<char, int>&m, string& nt, int l, int r)
	{
		if (l >= r)
			return;
		int i = l;
		int j = r + 1;
		do
		{
			do ++i;    while (i<r && (m[nt[i]] == 0 || m[nt[i]]>m[nt[l]]));
			do --j;    while (j>l && (m[nt[j]] == 0 || m[nt[j]]<m[nt[l]]));
			if (i<j)
				swap(nt[i], nt[j]);
		} while (i<j);
		swap(nt[l], nt[j]);
		fastSort(m, nt, l, j - 1);
		fastSort(m, nt, j + 1, r);

	}
	string customSortString(string S, string T) {
		map<char, int>m;
		int n = S.length();
		for (auto it = S.begin();it != S.end();++it)
			m[*it] = n--;
		string nt = T;
		fastSort(m, nt, 0, nt.length() - 1);
		return nt;
	}
};