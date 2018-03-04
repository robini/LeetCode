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
	int widthOfBinaryTree(TreeNode* root) {
		vector<int> lefts;
		return dfs(root, 1, 0, lefts);
	}
	int dfs(TreeNode* root, int id, int d, vector<int>& lefts)
	{
		if (!root)   return 0;
		if (d >= lefts.size()) lefts.push_back(id);
		return max({ id + 1 - lefts[d], dfs(root->left, id * 2, d + 1, lefts), dfs(root->right, id * 2 + 1, d + 1, lefts) });
	}
};