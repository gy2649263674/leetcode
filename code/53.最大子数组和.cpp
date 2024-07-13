/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// #include <bits\stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[100000] = {0};
    int maxSubArray(vector<int> &nums)
    {
        //int ans = *min_element(nums.begin(),nums.end());
        int ans;
        dp[0] = nums[0];// = max(0, nums[0]);
        ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);//最开始就是最小值
        }
        return max(ans,dp[nums.size()-1]);
    }
};
// @lc code=end
