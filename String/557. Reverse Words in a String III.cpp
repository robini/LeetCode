class Solution {
public:
	string reverseWords(string s) {
		string news;
		string word = "";
		string space = " ";
		int len = s.length();
		for (int i = len - 1;i >= 0;i--)
		{
			if (s[i] != ' ')
			{
				word += s[i];
			}
			else
			{
				news = space + word + news;
				word = "";
			}
		}
		news = word + news;
		return news;
	}
};