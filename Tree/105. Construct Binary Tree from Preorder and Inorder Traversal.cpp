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
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preR, int l, int r)
	{
		TreeNode* t = new TreeNode(preorder[preR]);
		int i = l;
		for (;i <= r;++i)
		{
			if (inorder[i] == preorder[preR])
				break;
		}
		if (l<i)
			t->left = helper(preorder, inorder, preR + 1, l, i - 1);
		if (i<r)
			t->right = helper(preorder, inorder, preR + 1 + i - l, i + 1, r);
		return t;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = preorder.size();
		if (n == 0)
			return nullptr;
		return helper(preorder, inorder, 0, 0, n - 1);
	}
};