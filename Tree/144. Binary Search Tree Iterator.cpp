/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator {
private:
	vector<int> nums;

	void helper(TreeNode *root)
	{
		if (root != NULL)
		{
			helper(root->right);
			nums.push_back(root->val);
			helper(root->left);
		}

	}
public:
	BSTIterator(TreeNode *root) {
		helper(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return (!nums.empty());
	}

	/** @return the next smallest number */
	int next() {
		int num = nums.back();
		nums.pop_back();
		return num;

	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/