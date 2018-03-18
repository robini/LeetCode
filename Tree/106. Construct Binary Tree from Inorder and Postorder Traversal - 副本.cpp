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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		if (n == 0)
			return nullptr;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
		TreeNode* root = nullptr;
		stack<TreeNode*> s;
		for (int i = n - 1, j = n - 1;i >= 0;--i)
		{
			while (!s.empty() && s.top()->val == inorder[j])
			{
				left = s.top();
				s.pop();
				--j;
			}
			TreeNode* t = new TreeNode(postorder[i]);
			if (root == nullptr)
				root = t;
			if (left != nullptr)
			{
				left->left = t;
			}
			if (!s.empty() && left == nullptr)
			{
				s.top()->right = t;
			}
			left = nullptr;
			s.push(t);


		}



		return root;
	}
};