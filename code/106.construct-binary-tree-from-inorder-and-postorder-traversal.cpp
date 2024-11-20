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
// @lcpr-template-end
// @lc code=start
/**
  Definition for a binary tree node.
  */
#ifdef LOCAL
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif
#include <bits/stdc++.h>
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        // function<TreeNode *(int ls, int rs, int sl, int sr)> build = [&](int cur, int ls, int rs, int sl, int sr) -> TreeNode *
        function<TreeNode *(int, int rs, int sl, int sr)> build = [&](int il, int ir, int pl, int pr) -> TreeNode *
        {
            // the current position of root and the left boundry determine the size of left tree actually
            // the cur is the position
            if (il > ir || pl > pr || pl < 0 || pr < 0)
                return NULL;
            if (pl == pr)
            {
                return new TreeNode(postorder[pr]);
            }
            int cur = pr;
            TreeNode *root = new TreeNode(postorder[cur]);
            int pos = mp[postorder[cur]];
            int lsize = pos - il;
            int rsize = ir - pos;

            root->right = build(pos + 1, ir, pr  - rsize, pr - 1);
            root->left = build(il, pos - 1, pr - rsize - lsize, pr - rsize - 1);
            return root;
        };
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end
void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Solution s;
    vector<int> inorder = {1, 2};
    vector<int> postorder = {2, 1};
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> postorder = {9, 15, 7, 20, 3};
    // s.buildTree(inorder, postorder);
    preorder(s.buildTree(inorder, postorder));
    return 0;
}
/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
