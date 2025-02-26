/*
 * @lc app=leetcode.cn id=99 lang=cpp
 * @lcpr version=30204
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode.cn/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (60.86%)
 * Likes:    968
 * Dislikes: 0
 * Total Accepted:    158.6K
 * Total Submissions: 260.4K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
 *
 *      dd2
 *
 * 示例 1：
 *
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 *
 *
 * 示例 2：
 *
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 *
 *
 *
 * 提示：
 *
 *
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1) 空间的解决方案吗？
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        vector<int> arr;
        function<void(TreeNode *)> inorder = [&](TreeNode *node) -> void
        {
            if (!node)
                return;
            inorder(node->left);
            arr.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        int l1 = -1, l2 = -1;
        for (int i = 0; i + 1 < arr.size(); i++)
        {
            cout << arr[i] << " ";
            if (arr[i] > arr[i + 1])
            {
                l1 = i;
                break;
            }
        }
        for (int i = arr.size() - 1; i - 1 >= 0; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                l2 = i;
                break;
            }
        }
        // cout << l1 << " " << l2 << endl;
        function<void(TreeNode *)> find = [&](TreeNode *node) -> void
        {
            if (!node)
                return;
            if (node->val == arr[l1] || node->val == arr[l2])
            {
                node->val = node->val == arr[l1] ? arr[l2] : arr[l1];
            }
            find(node->left);
            find(node->right);
        };
        find(root);
        return;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,null,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,null,null,2]\n
// @lcpr case=end

 */
