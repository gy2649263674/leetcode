#include <bits\stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// #include <bits/stdc++.h>
class Solution
{
public:
	vector<TreeNode *> build(int l, int r, int root)
	{
		if (l == r)
		{
			TreeNode *temp = new TreeNode(l, NULL, NULL);
			return vector<TreeNode *>({temp});
		}
		else
		{
			vector<TreeNode *> le;
			vector<TreeNode *> ri;
			if (root - 1 >= l)
			{
				le = build(l, root - 1, root);
			}
			if (root + 1 <= r)
			{
				ri = build(root + 1, r, root);
			}
			le.push_back(new TreeNode(0, 0, 0));
			ri.push_back(new TreeNode(0, 0, 0));
			vector<TreeNode *> ans;
			for (int i = 0; i < le.size(); i++)
			{
				for (int j = 0; j < ri.size(); j++)
				{
					TreeNode *temp = new TreeNode(root, le[i], ri[j]);
					ans.push_back(temp);
				}
			}
			return ans;
		}
	}
	vector<TreeNode *> generateTrees(int n)
	{
		vector<TreeNode *> ans;
		for (int i = 1; i <= n; i++)
		{
			vector<TreeNode *> temp = build(1, 8, i);
			for (TreeNode *var : temp)
			{
				ans.push_back(var);
			}
		}
		return ans;
	}
};
int main(void)
{
	Solution s;
	s.generateTrees(4);
	return 0;
}