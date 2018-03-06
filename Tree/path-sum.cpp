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

	bool helper(TreeNode* t, int sum, int cur)
	{
		if (t != NULL)
		{
			cur += t->val;
			if (t->left == NULL&&t->right == NULL)
			{
				return (cur == sum);
			}
			else
			{
				return helper(t->left, sum, cur) || helper(t->right, sum, cur);
			}

		}
		return false;

	}
	bool hasPathSum(TreeNode* root, int sum) {

		return helper(root, sum, 0);
	}
};