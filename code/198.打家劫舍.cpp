// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[100][2];
        //the max pro for former items;
        //second is today do it or not;
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i][1] = dp[i-1][0]+nums[i];
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        int i  = nums.size();
    return max(dp[i-1][0],dp[i-1][1]);
    }
};
// @lc code=end

