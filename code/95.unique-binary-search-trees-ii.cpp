/*
 * @lc app=leetcode.cn id=95 lang=cpp
 * @lcpr version=30204
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode.cn/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (74.14%)
 * Likes:    1572
 * Dislikes: 0
 * Total Accepted:    196K
 * Total Submissions: 264.3K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 *
 *
 */
#define LOCAL

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

// Definition for a binary tree node.
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
    vector<TreeNode *> generateTrees(int n)
    {
        // for(int i = 0)
        // pre
        function<void(TreeNode *, deque<int> &)> fill = [&](TreeNode *root, deque<int> &vals) -> void
        {
            if (root == NULL)
            {
                return;
            }
            else
            {
                fill(root->left, vals);
                root->val = vals.front();
                vals.pop_front();
                fill(root->right, vals);
                return;
            }
        };
        function<vector<TreeNode *>(TreeNode *, int tt)> dfs = [&](TreeNode *root, int tt) -> vector<TreeNode *>
        {
            // get the left an dgte the right
            if (tt == 0)
            {
                return vector<TreeNode *>({root});
            }
            else
            {
                root = new TreeNode();
                vector<TreeNode *> cur;
                for (int i = 0; i <= tt - 1; i++)
                {
                    auto v1 = dfs(root->left, i);
                    auto v2 = dfs(root->right, tt - i - 1);
                    for (auto r1 : v1)
                    {
                        for (auto r2 : v2)
                        {
                            TreeNode *tmp = new TreeNode;
                            tmp->left = r1;
                            tmp->right = r2;
                            cur.push_back(tmp);
                        }
                    }
                }
                return cur;
            }
        };
        auto v = dfs(0, n);
        for (auto val : v)
        {
            deque<int> q(n);
            iota(q.begin(), q.end(), 1);
            fill(val, q);
        }
        return v;
    }
};

// @lc code=end

void pre(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "NULL  ";
        return;
    }
    else
    {
        cout << root->val << "  ";
        pre(root->left);
        pre(root->right);
    }
}
int main(void)
{
    Solution s;
    auto res = s.generateTrees(3);
    for (auto r : res)
    {
        // preorder
        // cout << r->val << endl;
        pre(r);
        cout << endl;
    }
    return 0;
}
/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

// function<void(int, int, TreeNode *, TreeNode *)> dfs = [&](TreeNode *root, TreeNode *now) -> void
//     {
//         if (cur != n + 1)
//         {
//             TreeNode *tmp = new TreeNode(cur);
//         }
//         else
//         {
//             return;
//         }
//         if (sta == (1 << n + 1) + (1 << n) - 1)
//         {
//             // copy the tree and push into
//             ans.push_back(build(root, NULL));
//             return;
//         }
//         else
//         {
//             dfs(root, root->left = new TreeNode);
//             dfs(root, root->right = new TreeNode);

//             for (int i = 1; i <= n + 1; i++)
//             {
//                 if (sta & 1 << i)
//                 {
//                     sta &= 1 << i;
//                     for (int j = 1; j <= n + 1; j++)
//                     {
//                         if (sta & 1 << j)
//                         {
//                             if (j != n + 1)
//                                 sta &= 1 << j;
//                             dfs() if (j != n + 1)
//                                 sta ^= 1 << j;
//                         }
//                     }
//                     sta ^= 1 << i;
//                 }
//             }
//         }
//     };
// }

// } function<void(TreeNode *, TreeNode *, TreeNode *, int tt)>
//                                                                                           dfs = [&](TreeNode *tar, TreeNode *l, TreeNode *r, int tt) -> void
// {
//     if (tt > n)
//     {
//         return;
//     }
//     if (tt == n)
//     {
//         deque<int> aux;
//         iota(aux.begin(), aux.end(), n);
//         ans.push_back(build(tar, NULL, aux));
//     }
//     else
//     {
//         for (int i = 0; i < n - tt; i++)
//         {
//             dfs(tar->left = new TreeNode(), tar->right = new TreeNode(), tt + 2);
//             dfs(tar)
//         }
//         delete tar->left;
//         delete tar->right;
//         dfs(tar->left = new TreeNode(), NULL, tt + 1);
//         delete tar->left;
//         dfs(NULL, tar->right = new TreeNode(), tt + 1);
//         delete tar->right;
//         return;
//     }
// };