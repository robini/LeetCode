/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		while (root)
		{
			TreeLinkNode * pre = nullptr;
			for (auto cur = root; cur; cur = cur->next)
			{
				if (cur->left)
				{
					if (!pre)
						root = cur->left;
					else
						pre->next = cur->left;
					pre = cur->left;
				}
				if (cur->right)
				{
					if (!pre)
						root = cur->right;
					else
						pre->next = cur->right;
					pre = cur->right;
				}
			}
			if (!pre)
				break;
		}
	}
};