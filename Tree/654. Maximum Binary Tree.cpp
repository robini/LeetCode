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

	TreeNode* cmbt(int l, int r, vector<int>& nums)
	{
		TreeNode* troot = new TreeNode(nums[l]);
		int maxIdx = l;
		for (int i = l + 1;i <= r;i++)
		{
			if (nums[i]>troot->val)
			{
				troot->val = nums[i];
				maxIdx = i;
			}
		}
		if (maxIdx>l)
			troot->left = cmbt(l, maxIdx - 1, nums);
		if (maxIdx<r)
			troot->right = cmbt(maxIdx + 1, r, nums);
		return troot;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		int len = nums.size();
		TreeNode* troot = cmbt(0, len - 1, nums);
		return troot;

	}
};