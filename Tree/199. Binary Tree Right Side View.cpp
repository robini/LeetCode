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

	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		deque<TreeNode*> dq;
		dq.push_back(root);
		dq.push_back(NULL);
		int curVal = root->val;

		while (!dq.empty())
		{
			TreeNode* t = dq.front();
			dq.pop_front();
			if (t == NULL)
			{
				res.push_back(curVal);
				if (!dq.empty())
				{
					dq.push_back(NULL);
				}
			}
			else
			{
				curVal = t->val;
				if (t->left != NULL)
					dq.push_back(t->left);
				if (t->right != NULL)
					dq.push_back(t->right);
			}
		}
		return res;

	}
};