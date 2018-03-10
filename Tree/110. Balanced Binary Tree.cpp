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

	int helper(TreeNode* root)
	{
		if (root != nullptr)
		{
			int l = helper(root->left);
			if (l == -1)
				return -1;
			int r = helper(root->right);
			if (r == -1)
				return -1;
			if ((l - r<-1) || (l - r>1))
				return -1;
			return max(l, r) + 1;
		}
		return 0;

	}
	bool isBalanced(TreeNode* root) {
		if (root != nullptr)
		{
			int l = helper(root->left);
			if (l == -1)
				return false;
			int r = helper(root->right);
			if (r == -1)
				return false;
			return (l - r>-2) && (l - r<2);

		}
		return true;
	}
};