class Solution {
public:
	struct compare {
		bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
			return a.first > b.first;
		}
	};

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		if (n == 0)
			return 0;
		priority_queue<pair< int, pair<int, int> >, vector< pair<int, pair<int, int> > >, compare> pq;
		for (int i = 0; i<matrix[0].size(); i++)
			pq.push(make_pair(matrix[0][i], make_pair(0, i)));

		int minValue = matrix[0][0];
		while (k != 0) {
			minValue = pq.top().first;
			int i = pq.top().second.first;
			int j = pq.top().second.second;
			pq.pop();
			if (i<n - 1)
			{
				pq.push(make_pair(matrix[i + 1][j], make_pair(i + 1, j)));
			}
			k--;
		}

		return minValue;
	}
};