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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		vector<int> level;
		deque<TreeNode*> dq;
		dq.push_back(root);
		dq.push_back(NULL);

		while (!dq.empty())
		{
			TreeNode* t = dq.front();
			dq.pop_front();
			if (t == NULL)
			{
				res.push_back(level);
				level.clear();
				if (!dq.empty())
				{
					dq.push_back(NULL);
				}
			}
			else
			{
				level.push_back(t->val);
				if (t->left != NULL)
					dq.push_back(t->left);
				if (t->right != NULL)
					dq.push_back(t->right);
			}
		}
		return res;
	}
};