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
	string pathToStr(TreeNode* t, unordered_map<string, vector<TreeNode*>>& mp)
	{
		if (t == nullptr)
			return "";
		string str = "(" + pathToStr(t->left, mp) + to_string(t->val) + pathToStr(t->right, mp) + ")";
		mp[str].push_back(t);
		return str;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, vector<TreeNode*>> mp;
		vector<TreeNode*> res;
		pathToStr(root, mp);
		for (auto it = mp.begin();it != mp.end();it++)
			if (it->second.size()>1)
				res.push_back(it->second[0]);
		return res;
	}
};