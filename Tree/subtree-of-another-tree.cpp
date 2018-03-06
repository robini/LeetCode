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
	void getNodes(int val, TreeNode* root, vector<TreeNode*>& nodes)
	{
		if (root)
		{
			if (root->val == val)
				nodes.push_back(root);
			getNodes(val, root->left, nodes);
			getNodes(val, root->right, nodes);
		}

	}
	bool Same(TreeNode* sChild, TreeNode* t)
	{
		if (!sChild && !t)
			return true;
		else if (sChild&&t)
		{
			if (sChild->val != t->val)
				return false;
			else
				return Same(sChild->left, t->left) && Same(sChild->right, t->right);
		}
		else
			return false;
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		vector<TreeNode*> nodes;
		getNodes(t->val, s, nodes);
		bool isSame = false;
		for (int i = 0;i<nodes.size();i++)
		{
			isSame = Same(nodes[i], t);
			if (isSame)
				break;
		}
		return isSame;
	}
};