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
private:
	vector<int> res;

	void helper(TreeNode* t, int& pre, int& cmt, int& maxCmt)
	{
		if (t != nullptr)
		{
			helper(t->left, pre, cmt, maxCmt);
			if (pre == t->val)
			{
				++cmt;
			}
			else
			{
				if (cmt>maxCmt)
				{
					res.clear();
					res.push_back(pre);
					maxCmt = cmt;
				}
				else if (cmt == maxCmt)
				{
					res.push_back(pre);
				}
				cmt = 1;
				pre = t->val;
			}
			helper(t->right, pre, cmt, maxCmt);
		}



	}

public:


	vector<int> findMode(TreeNode* root) {
		if (root == nullptr)
			return res;
		TreeNode* t = root;
		while (t->left != nullptr)
			t = t->left;
		int l = t->val;
		int cmt = 0;
		int maxCmt = 0;
		helper(root, l, cmt, maxCmt);

		if (cmt>maxCmt)
		{
			res.clear();
			res.push_back(l);
		}
		else if (cmt == maxCmt)
		{
			res.push_back(l);
		}

		return res;
	}
};