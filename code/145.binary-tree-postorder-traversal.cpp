#define LOCAL
/*


 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30204
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (76.83%)
 * Likes:    1200
 * Dislikes: 0
 * Total Accepted:    834.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 *
 * 输出：[3,2,1]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
 *
 * 输出：[4,6,7,5,2,9,8,3,1]
 *
 * 解释：
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 *
 * 输出：[]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1]
 *
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
// if (!root)
// {
//     return {};
// }
// deque<pair<TreeNode *, int>> st;
// // TreeNode *o = root;
// vector<int> ans;
// st.push_back({root, 0});
// auto o = st.back();
// while (st.empty() == false)
// {
//     if (o.second == 1)
//     {
//         ans.push_back(o.first->val);
//         st.pop_back();
//         if (st.empty())
//         {
//             return ans;
//         }
//         o = st.back();
//         st.back().second = 1;
//         continue;
//     }
//     while (o.first->left)
//     {
//         st.push_back({o.first->left, 0});
//         o = {o.first->left, 0};
//     }
//     if (!o.first->right)
//     {
//         ans.push_back({o.first->val});
//         st.pop_back();
//         if (st.empty())
//         {
//             return ans;
//         }
//         st.back().second = 1;
//         o = st.back();
//         // o.second = 1;
//     }
//     else
//     {
//         st.back().second = 1;
//         o = {o.first->right, 0};
//         st.push_back(o);
//     }
// }
// return ans;
// @lcpr-template-end
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
//@lc code=start
// vector<int> postorderTraversal1(TreeNode *root)

// {
//     if (root == NULL)
//     {
//         return {};
//     }
//     else
//     {
//         vector<int> ans;
//         stack<TreeNode *> aux;
//         while (!aux.empty())
//         {
//             /* code */
//             while (root)
//             {
//                 aux.push(root);
//                 root = root->left;
//             }
//             root = aux.top();
//             if (root->right)
//             {
//                 aux.push(root->right);
//                 continue;
//             }
//             else
//             {
//                 ans.push_back(root->val);
//                 aux.pop();
//             }
//             return ans;
//         }

//         aux.push(root);
//         TreeNode *prev = new TreeNode(100001);
//         while (!aux.empty())
//         {
//             root = aux.top();
//             while (root->left && prev != root->right && prev != root->left)
//             {
//                 aux.push(root->left);
//                 root = aux.top();
//             }
//             if (root->right == NULL || prev == root->right)
//             {
//                 ans.push_back(root->val);
//                 prev = root;
//                 aux.pop();
//             }
//             else
//             {
//                 aux.push(root->right);
//             }
//         }
//         return ans;
//     }
// }
// *
//  Definition for a binary tree node.
// firstly set the vi is false,when the root is at top and  after pushed all children into the stack set the able to true 
// if meet true then the root can be pope
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<pair<TreeNode *, bool>> aux;
        vector<int> ans;
        aux.push({root, false});
        while (aux.empty() == false)
        {
            // auto [root, able] = aux.top();
            root = aux.top().first;
            bool able = aux.top().second;
            aux.pop();
            if (able)
            {
                ans.push_back(root->val);
            }
            else
            {
                // aux.pop();
                aux.push({root, true});
                if (root->right)
                {
                    aux.push({root->right, false});
                }
                if (root->left)
                {
                    aux.push({root->left, false});
                }
            }
        }
        return ans;
    }
    //
    /* code */
};

/* code */
// @lc code=end
int main(void)
{
    Solution s;
    // vector<int> v = {1, 2, 3, 4, 5, NULL, 8, NULL, NULL, 6, 7, 9};
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    s.postorderTraversal(root);
    return 0;
}
/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
