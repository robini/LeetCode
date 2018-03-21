
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int N = M.size();
		if (N == 0)
			return 0;
		int circles = 0;
		stack<int> f;

		for (int i = 0;i<N;++i)
		{
			if (f.empty() && M[i][i] == 1)
			{
				++circles;
				f.push(i);
				while (!f.empty())
				{
					int j = f.top();
					f.pop();
					M[j][j] = 0;
					for (int k = 0;k<N;++k)
					{
						if (M[j][k] == 1 && M[k][k] == 1)
							f.push(k);
					}
				}

			}
		}

		return circles;
	}
};