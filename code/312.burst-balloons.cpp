/*
 * @lc app=leetcode.cn id=312 lang=cpp
 * @lcpr version=30203
 *
 * [312] 戳气球
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
class Solution
{
public:
    int dp[500][500] = {0};
    int solve(int l, int r, vector<int> &nums)
    {

        if (dp[l][r] != 0)
        {
            return dp[l][r];
        }
        if (l >= r)
        {
            return 0;
        }
        for (int i = l + 1; i < r; i++)
        {
            dp[l][r] = max(dp[l][r], solve(l, i, nums) + solve(i, r, nums) + nums[l] * nums[r] * nums[i]);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int len = 0;len<nums.size();len++)
        {
            for (int l = 0; l < nums.size()-len; l++)
            {
                for (int m = l + 1; m < l+len; m++)
                {
                    dp[l][len] = max(dp[l][len], dp[l][m-l] + dp[m][l+len-m] + nums[l] * nums[l+len] * nums[m]);
                }
            }
        }
        return dp[0][nums.size() - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,1,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n
// @lcpr case=end

 */
