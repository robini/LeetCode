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

	TreeNode* satb(int l, int r, vector<int>& nums)
	{
		if (l>r)
			return NULL;
		int mid = (r + l) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = satb(l, mid - 1, nums);
		root->right = satb(mid + 1, r, nums);

		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		int len = nums.size();
		TreeNode* root = satb(0, len - 1, nums);
		return root;
	}
};