/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] 感染二叉树需要的总时间
 */

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
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    std::map<int, vector<int>> mp;
    void build(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        else
        {
            if (r->left)
            {
                mp[r->val].push_back(r->left->val);
                mp[r->left->val].push_back(r->val);
                build(r->left);
            }
            if (r->right)
            {

                mp[r->val].push_back(r->right->val);
                mp[r->right->val].push_back(r->val);
                build(r->right);
            }
        }
    }
    int amountOfTime(TreeNode *root, int start)
    {
        build(root);
        queue<int> aux;
        set<int> vis;
        aux.push(start);
        vis.insert(start);
        int cnt = 0;
        while (!aux.empty())
        {
            cnt++;
            int num = aux.size();
            while (num--)
            {
                int temp = aux.front();
                for (int var : mp[temp])
                {
                    if (vis.count(var) == 0)
                    {
                        aux.push(var);
                        vis.insert(var);
                    }
                }
                aux.pop();
            }
        }
        return cnt-1;
    }
};
// @lc code=end
