/*
 * @lc app=leetcode.cn id=1186 lang=cpp
 * @lcpr version=30204
 *
 * [1186] 删除一次得到子数组最大和
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
	int maxsubarr(vector<int> arr)
	{
		int n = arr.size();
		int dp[10000] = {0};
		int ans = -1e9;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = max(dp[i - 1], 0) + arr[i - 1];
			ans = max(ans, dp[i]);
		}
		return ans;
	}
	int maximumSum(vector<int> arr)
	{
		int n = arr.size();
		int dp[100003][2] = {0};
		dp[0][0] = 0;
		int ans = -1e9;
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], 0) + arr[i - 1];
			dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
		}
		ans = dp[1][0];
		for (int i = 2; i <= n; i++)
		{
			ans = max({ans,dp[i][0],dp[i][1]});
		}
		return ans;
	}
};
// @lc code=end

int main(void)
{
	Solution s;
	cout << s.maxsubarr({1, 2, -1, 2});
	// cout<<s.maximumSum(vector<int>{1, -2, 0, 3});
	return 0;
}

/*
// @lcpr case=start
// [1,-2,0,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,-2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1,-1,-1]\n
// @lcpr case=end

 */
