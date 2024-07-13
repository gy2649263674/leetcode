/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30204
 *
 * [102] 二叉树的层序遍历
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
/**/

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(!root)
        {
            return {};
        }
        queue<TreeNode *> aux;
        aux.push(root);
        int cur = 0;
        vector<vector<int>>ans;
        while (aux.empty() == 0)
        {
            int si = aux.size();
            ans.push_back(vector<int>());
            while (si--)
            {
                auto it = aux.front();
                ans[cur].push_back(it->val);
                if (it->left)
                {
                    aux.push(it->left);
                }
                if (it->right)
                {
                    aux.push(it->right);
                }
                aux.pop();
            }
            ++cur;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
