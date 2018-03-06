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
	void helper(TreeNode* t, int sum, int cur, vector<vector<int>>&res, vector<int>& vec)
	{
		if (t)
		{
			cur += t->val;
			vec.push_back(t->val);
			if (!t->left && !t->right)
			{
				if (cur == sum)
				{
					res.push_back(vec);
				}

			}
			else
			{
				vector<int> temp = vec;
				helper(t->left, sum, cur, res, vec);
				helper(t->right, sum, cur, res, temp);
			}
		}
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> t;
		helper(root, sum, 0, res, t);
		return res;
	}
};