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
	bool checkone(TreeNode* t)
	{
		bool l = true;
		bool r = true;
		if (t->left&&checkone(t->left));
		else
		{
			l = false;
			t->left = nullptr;
		}

		if (t->right&&checkone(t->right));
		else
		{
			r = false;
			t->right = nullptr;

		}
		return(l || r || t->val == 1);

	}
	TreeNode* pruneTree(TreeNode* root) {
		checkone(root);
		return root;
	}
};