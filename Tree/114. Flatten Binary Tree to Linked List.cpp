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
	TreeNode* helper(TreeNode* t)
	{
		if (!t)
			return nullptr;
		TreeNode* l = t->left;
		TreeNode* r = t->right;
		t->left = nullptr;
		t->right = helper(l);
		l = t;
		while (l->right)
			l = l->right;
		l->right = helper(r);
		return t;
	}
	void flatten(TreeNode* root) {
		helper(root);
	}
};