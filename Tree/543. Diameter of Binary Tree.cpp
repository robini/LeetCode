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
	int Height(TreeNode* root)
	{
		if (!root)
			return 0;
		int l = Height(root->left);
		int r = Height(root->right);
		return l>r ? l + 1 : r + 1;
	}

	int diameterOfBinaryTree(TreeNode* root)
	{
		if (!root)   return 0;
		int l = Height(root->left);
		int r = Height(root->right);
		int diameter = l + r;
		TreeNode* proot = root;
		while (l != r)
		{
			if (l>r)
				proot = proot->left;
			else
				proot = proot->right;
			l = Height(proot->left);
			r = Height(proot->right);
			if (l + r>diameter)
				diameter = l + r;
		}

		return diameter;
	}
};