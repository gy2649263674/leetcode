/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() <= 3)
		{
			return *max_element(nums.begin(), nums.end());
		}
		int ans1 = nums[0], ans2 = 0;
		int dp[101][2] = {0};
		; // 一号必选
		dp[2][1] = nums[2];
		dp[2][0] = 0;
		int i = 2;
		for (; i < nums.size() - 1; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + nums[i];
		}
		ans1 = max(dp[i-1][0], dp[i-1][1]) + nums[0];
		// fill(dp[0], sizeof(dp), 0);
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 0;
		dp[1][1] = nums[1];
		i = 2;
		for (; i < nums.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + nums[i];
		}
		ans2 = max(dp[i-1][0], dp[i-1][1]);
		return max(ans1, ans2);
	}
};
// @lc code=end
