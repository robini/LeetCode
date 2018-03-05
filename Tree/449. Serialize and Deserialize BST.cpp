/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		deque<TreeNode*> dq;
		dq.push_back(root);
		int nNULL = 0;
		while (!dq.empty())
		{
			int n = dq.size();
			for (int i = 0;i<n;i++)
			{
				TreeNode* t = dq.front();
				dq.pop_front();
				if (t == NULL)
				{
					res += 'n';
					nNULL++;
				}
				else
				{
					res += std::to_string(t->val);
					res += 'x';
					dq.push_back(t->left);
					dq.push_back(t->right);
				}

			}
			if (n == nNULL)
				break;
			n = dq.size();
			nNULL = 0;
		}
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data[0] == 'n')
			return NULL;
		int n = data.length();
		int starti = 0;
		int endi = 0;
		TreeNode* t;
		vector<TreeNode*> nodes;
		int num = 0;
		int i = 0;
		while (i<n)
		{
			if (isdigit(data[i]))
			{
				while (isdigit(data[i]))
					i++;
				int val = atoi(data.substr(starti, i - starti + 1).c_str());         //string sub = data.slice(starti,endi+1);
				t = new TreeNode(val);
				nodes.push_back(t);
			}
			else
				t = NULL;
			starti = endi = ++i;
			num++;
			if (num / 2 == 0)
				continue;
			if (num % 2 == 0)
				nodes[num / 2 - 1]->left = t;
			else
				nodes[num / 2 - 1]->right = t;

		}
		return nodes[0];
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));