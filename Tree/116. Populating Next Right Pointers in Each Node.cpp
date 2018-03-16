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
		if (root == nullptr)
			return;
		TreeLinkNode* curPar = root;
		while (curPar->left != nullptr)
		{
			curPar->left->next = curPar->right;
			TreeLinkNode* t = curPar;
			while (t->next != nullptr)
			{
				t->right->next = t->next->left;
				t->next->left->next = t->next->right;
				t = t->next;
			}
			curPar = curPar->left;
		}



	}
};