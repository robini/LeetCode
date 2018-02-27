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
	void findRow(TreeNode* root, int d, int v, int curRow) {
		if (root)
		{
			if (curRow == d)
			{
				TreeNode* preLeft = root->left;
				TreeNode* preRight = root->right;
				root->left = new TreeNode(v);
				root->right = new TreeNode(v);
				root->left->left = preLeft;
				root->right->right = preRight;
			}
			else if (curRow<d)
			{
				findRow(root->left, d, v, curRow + 1);
				findRow(root->right, d, v, curRow + 1);
			}
		}


	}

	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1)
		{
			TreeNode* newR = new TreeNode(v);
			newR->left = root;
			return newR;
		}
		findRow(root, d - 1, v, 1);
		return root;
	}
};