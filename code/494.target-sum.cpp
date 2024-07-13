/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30204
 *
 * [494] 目标和
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
// class Solution
// {
// public:
//     vector<int> arr;
//     unordered_map<int, int> dp[31];
//     int solve(int in, int tar)
//     {
//         if (dp[in].count(tar))
//         {
//             return dp[in][tar];
//         } // suf satisfy the tar
//         else if (in == arr.size() - 1)
//         { // suo xu hou zhui
//             return tar == arr[in]+(-arr[in] == tar);
//         }
//        return  dp[in][tar] = solve(in + 1, tar - arr[in]) + solve(in + 1, tar + arr[in]);
//     }
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         arr = nums;
//         return solve(0,target);
//     }
// };

class Solution
{
public:
    // sum -neg -neg = tar;
    // neg = (sum-tar)/2;
    // find some nums that sums
    int findTargetSumWays(vector<int>& nums, int tar)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        double nt = (sum - tar) / 2.0;
        if (nt != ceil(nt) || nt != floor(nt)||nt<0)
        {
            return  0;
        }
        int n = nums.size();
        int dp[30][2000] = {0};
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= nt; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (j >= nums[i - 1])
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][int(nt)];

    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
