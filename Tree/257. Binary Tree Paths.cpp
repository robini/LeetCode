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
	void helper(TreeNode* t, vector<string>&res, string s)
	{
		if (t)
		{
			s += to_string(t->val);
			if (!t->left && !t->right)
			{
				res.push_back(s);
				s = "";
			}
			else
			{
				s += "->";
				helper(t->left, res, s);
				helper(t->right, res, s);
			}
		}
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string s = "";
		helper(root, res, s);
		return res;
	}
};