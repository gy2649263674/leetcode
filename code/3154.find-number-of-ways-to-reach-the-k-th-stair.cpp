/*
 * @lc app=leetcode.cn id=3154 lang=cpp
 * @lcpr version=30204
 *
 * [3154] 到达第 K 级台阶的方案数
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
	int tar;
	int ans = 0;
	map<pair<int, int>, int> dp[2];
	// int dp[][]
	int dfs(int cur, int j, bool ok)
	{ // min = 1<<j+1 - 2
		if (cur < 0)
		{
			return 0;
		}
		if (cur - 1 > tar)
		{
			return 0;
		}
		if (dp[ok].count({cur, j}))
		{
			return dp[ok][{cur, j}];
		}
		if (ok == true)
		{
			return dp[ok][{cur, j}] = dfs(cur - 1, j, false) + dfs(cur + (1 << j), j + 1, true) + (cur == tar ? 1 : 0);
		}
		else
		{
			return dp[ok][{cur, j}] = dfs(cur + (1 << j), j + 1, true) + (cur == tar ? 1 : 0);
			;
		}
	}
	int waysToReachStair(int k)
	{
		return way_2(k);
		tar = k;
		return dfs(1, 0, true);
	}
	int way_2(int k)
	{
		// after n times has walked least 1 time
		// min is 1+1-1
		// 1+2
		//[2^n-1-n-1 ,2^n-1] most up step
		//  end with interval  [1<<n-n-1,1<<n]
		// if k in
		int ans = 0;
		auto com = [](int m, int n) -> long long
		{
			long long ori = m - n, tmp = 1;
			for (long long i = 1; i <= m - n; i++)
			{
				tmp*= (n+i);
				tmp/= (i);
			}
			return tmp;
		};
		//up+down = k
		//j-m = k
		//(1<<j-1)-k = m 
		//up j times most down j+1 times
		//m should small than j+1 and bigger than 0;
		for (int i = 0;(1 << i) - i - 1<=k&& i <= 30; i++)
		{
			int l = (1 << i) - i - 1, r = 1 << i;
			if (k >= l && k <= r)
			{
				ans += com(i + 1, r - k);
			}
		}
		return ans;
	}
};
// @lc code=end

/*
// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
int main(void)
{
	Solution ss;
	cout << ss.waysToReachStair(0);
	return 0;
}