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
	bool helper(TreeNode* l, TreeNode* r)
	{
		if (!r && !l)
			return true;
		else if (r&&l)
		{
			if (r->val != l->val)
				return false;
			return helper(l->left, r->right) && helper(l->right, r->left);
		}
		else
			return false;

	}

	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return helper(root->left, root->right);
	}
};