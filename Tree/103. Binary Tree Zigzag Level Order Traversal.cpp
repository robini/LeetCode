/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		deque<TreeNode*> q;
		bool order = false;
		q.push_back(root);
		vector<int> row;
		while (!q.empty())
		{
			int n = q.size();
			for (int i = n - 1;i >= 0;i--)
			{
				TreeNode* t = q.front();
				q.pop_front();;
				row.push_back(t->val);
				if (t->left != nullptr)
					q.push_back(t->left);
				if (t->right != nullptr)
					q.push_back(t->right);

			}
			if (order)
				reverse(row.begin(), row.end());
			res.push_back(row);
			row.clear();
			order = !order;
		}
		return res;




	}
};