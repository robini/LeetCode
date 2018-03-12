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

	int helper(TreeNode* root, int sum)
	{
		if (root == nullptr)
			return 0;
		else if (root->left == nullptr&&root->right == nullptr)
			return sum * 10 + root->val;
		else
			return helper(root->left, sum * 10 + root->val) + helper(root->right, sum * 10 + root->val);
	}
	int sumNumbers(TreeNode* root) {
		return helper(root, 0);
	}
};