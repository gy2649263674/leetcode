/*
 * @lc app=leetcode.cn id=572 lang=cpp
 * @lcpr version=30204
 *
 * [572] 另一棵树的子树
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
    bool dfs(TreeNode *root, TreeNode *subRoot, bool must)
    {

        if (root == NULL)
        {
            return subRoot == NULL;
        }
        if (subRoot == NULL)
        {
            return root == NULL;
        }
        if (must)
        {
            if (root->val == subRoot->val)
            {
                return (this->dfs(root->left, subRoot->left, true) && this->dfs(root->right, subRoot->right, true));
                // ((this->dfs(root->left, subRoot, must)) || this->dfs(root->right, subRoot, must));
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (root->val == subRoot->val)
                return (this->dfs(root->left, subRoot->left, true) && this->dfs(root->right, subRoot->right, true)) ||
                       ((this->dfs(root->left, subRoot, must)) || this->dfs(root->right, subRoot, must));

            else
            {
                return ((this->dfs(root->left, subRoot, must)) || this->dfs(root->right, subRoot, must));
            }
        }
        // return this->dfs(root->left, subRoot, false) || this->dfs(root->right, subRoot, false);
        // return this->dfs(root->left, subRoot, false) || this->dfs(root->right, subRoot, false);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return dfs(root, subRoot, false);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,4,5,1,2]\n[4,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,2,null,null,null,null,0]\n[4,1,2]\n
// @lcpr case=end

 */
