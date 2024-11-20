#define LOCAL
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.53%)
 * Likes:    1272
 * Dislikes: 0
 * Total Accepted:    424.5K
 * Total Submissions: 585.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
 *
 *
 */

 // @lcpr-template-start
using namespace std;
#include <algorithm>
#include <map>

#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include "all.h"
// @lcpr-template-end
// @lc code=start
/**
  Definition for a binary tree node.
  */
#ifdef LOCAL
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif
// #include <bits/stdc++.h>

class Solution
{
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>> edges)
	{
		int mxind = 0;
		for (auto edge : edges)
			mxind = max({ mxind, edge[0], edge[1] });
		vector<int> pa(1001);
		function<int(int)> find = [&](int a) -> int
			{
				return pa[a] = pa[a] == a ? a : find(pa[a]);
			};
		function<bool(int cur)>dfs = [&](int cur)->bool
			{

			};
		auto merge = [&](int a, int b)
			{
				if (pa[find(b)] != pa[a] && pa[find(a)] != pa[b])
					pa[find(b)] = find(a);
			};
		auto check = [&](int ex) -> bool
			{
				for (int i = 0; i < edges.size(); i++)
				{
					if (i != ex)
					{
						merge(edges[i][0], edges[i][1]);
					}
				}
				int f = find(1);
				for (int i = 1; i <= mxind; i++)
				{
					if (find(i) != f)
					{
						return false;
					}
				}
				return true;
			};
		for (int i = edges.size() - 1; i >= 0; i--)
		{
			iota(pa.begin(), pa.end(), 0);
			if (check(i))
			{
				return edges[i];
			}
		}
		return {};
	}
};
// @lc code=end
int main(void)
{
	Solution s;
	vector<vector<int>> v = { {2, 1}, {3, 1}, {4, 2}, {1, 4} };
	auto ans = s.findRedundantDirectedConnection(v);
	cout << ans[0] << ans[1];
	// for ()
	return 0;
}
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
