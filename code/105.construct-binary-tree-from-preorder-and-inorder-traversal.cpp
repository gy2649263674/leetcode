/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.99%)
 * Likes:    2389
 * Dislikes: 0
 * Total Accepted:    722.3K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
//  @lc code=start
//
//  Definition for a binary tree node.
#ifdef LOCAL
#endif
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        
        
    }
    TreeNode *buildTree0(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> in;
        for (int i = 0; i < inorder.size(); i++)
        {
            in[inorder[i]] = i;
        }
        if (preorder.empty())
            return NULL;
        // build the tree in the preorder [l,r]
        function<TreeNode *(int l, int r, int, int)> build = [&](int l, int r, int il, int ir) -> TreeNode *
        {
            if (l > r)
            {
                return {};
            }
            if (l == r)
            {
                return new TreeNode(preorder[l]);
            }
            else
            {
                // in the range(l,r)
                // the l must be the root
                TreeNode *root = new TreeNode(preorder[l]);
                // int ls = rootpos - il;
                // leftson size
                int rootpos = in[preorder[l]];
                // in the preorder will first visit the whole left son and then the right son
                // the inorder will tell the size of the left and right son's size
                root->left = build(l + 1, l + rootpos - il, il, rootpos - 1);
                root->right = build(l + rootpos - il + 1, r, rootpos + 1, ir);
                return root;
            };
        };
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
        // return build(NULL, preorder[0]);
    }

    // TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder)
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
