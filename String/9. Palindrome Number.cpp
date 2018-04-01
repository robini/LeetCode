class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		int t = x;
		int reverse = 0;
		while (x / 10)
		{
			reverse = reverse * 10 + x % 10;
			x = x / 10;
		}

		return t == (reverse * 10 + x);
	}
};