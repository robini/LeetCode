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

	void helper(TreeNode* t, int sum, int cum, map<int, int>&rec, int& res)
	{
		if (t == nullptr)
			return;
		cum += t->val;
		res += rec[cum - sum];
		rec[cum]++;
		map<int, int> old = rec;
		helper(t->left, sum, cum, rec, res);
		helper(t->right, sum, cum, old, res);

	}
	int pathSum(TreeNode* root, int sum) {
		map<int, int> rec;
		rec[0] = 1;
		int res = 0;
		helper(root, sum, 0, rec, res);
		return res;
	}
};