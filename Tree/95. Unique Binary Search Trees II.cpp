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
	vector<TreeNode*> helper(int from, int to)
	{
		vector<TreeNode *> ret;
		if (to<from)
			ret.push_back(nullptr);
		else if (to == from)
			ret.push_back(new TreeNode(from));
		else
		{
			for (int i = from; i <= to; i++)
			{
				vector<TreeNode *> l = helper(from, i - 1);
				vector<TreeNode *> r = helper(i + 1, to);

				for (int j = 0; j<l.size(); j++)
				{
					for (int k = 0; k<r.size(); k++)
					{
						TreeNode * h = new TreeNode(i);
						h->left = l[j];
						h->right = r[k];
						ret.push_back(h);
					}
				}
			}
		}
		return ret;

	}
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
		{
			vector<TreeNode *> ret;
			return ret;
		}
		return helper(1, n);
	}
};