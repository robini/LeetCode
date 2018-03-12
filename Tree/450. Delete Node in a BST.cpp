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
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* toDelete = root;
		TreeNode* pParent = root;//
		while (toDelete != nullptr&&toDelete->val != key)
		{
			pParent = toDelete;
			if (toDelete->val < key)
				toDelete = toDelete->right;
			else
				toDelete = toDelete->left;
		}
		if (toDelete == nullptr)
			return root;
		TreeNode* pC = toDelete;
		if (toDelete->right != nullptr&&toDelete->left != nullptr)
		{
			pParent = toDelete;
			pC = toDelete->right;
			while (pC->left != nullptr)
			{
				pParent = pC;
				pC = pC->left;
			}
			toDelete->val = pC->val;
			toDelete = pC;
		}
		if (toDelete->right != nullptr)
			pC = toDelete->right;
		else
			pC = toDelete->left;
		if (toDelete == root)
			root = pC;
		else if (toDelete == pParent->left)
			pParent->left = pC;
		else
			pParent->right = pC;
		return root;
	}
};