/*
 * @lc app=leetcode.cn id=3251 lang=cpp
 * @lcpr version=30204
 *
 * [3251] 单调数组对的数目 II
 *
 * https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/description/
 *
 * algorithms
 * Hard (47.42%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 14.9K
 * Testcase Example:  '[2,3,2]'
 *
 * 给你一个长度为 n 的 正 整数数组 nums 。
 *
 * 如果两个 非负 整数数组 (arr1, arr2) 满足以下条件，我们称它们是 单调 数组对：
 *
 *
 * 两个数组的长度都是 n 。
 * arr1 是单调 非递减 的，换句话说 arr1[0] <= arr1[1] <= ... <= arr1[n - 1] 。
 * arr2 是单调 非递增 的，换句话说 arr2[0] >= arr2[1] >= ... >= arr2[n - 1] 。
 * 对于所有的 0 <= i <= n - 1 都有 arr1[i] + arr2[i] == nums[i] 。
 *
 *
 * 请你返回所有 单调 数组对的数目。
 *
 * 由于答案可能很大，请你将它对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,3,2]
 *
 * 输出：4
 *
 * 解释：
 *
 * 单调数组对包括：
 *
 *
 * ([0, 1, 1], [2, 2, 1])
 * ([0, 1, 2], [2, 2, 0])
 * ([0, 2, 2], [2, 1, 0])
 * ([1, 2, 2], [1, 1, 0])
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,5,5,5]
 *
 * 输出：126
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n == nums.length <= 2000
 * 1 <= nums[i] <= 1000
 *
 *
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
#define LOCAL
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(1010, 0));
        fill(dp[1].begin(), dp[1].begin() + nums[0] + 1, 1);
        // dp[1][i] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int k = 0; k <= 0 && k <= nums[i - 2] - nums[i - 1]; k++)
            {
                dp[i][0] = (dp[i - 1][0]) % (1000000000 + 7);
            }
            // if nums[i]>nums[i-1] then cur   
            for (int j = max(nums[i - 2] - nums[i - 1], 1); j <= nums[i - 1]; j++)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][min(0, nums[i - 2] - nums[i - 1]) + j - 1]) % (1000000000 + 7);
                // in this step actually :
                // dp[i][j] must has the same part with dp[i][j-1] ans just add dp[i-1][min(0,jnums[i-2]-nums[i-1])+j-1]
                // dp[i][j] = dp[i][j-d]
            }
        }
        // for (int i = 2; i <= n; i++)
        // {
        //     for (int j = 0; j <= nums[i - 1]; j++)
        //     {
        //         for (int k = 0; k <= j && k <= nums[i - 2] + j - nums[i - 1]; k++)
        //         {
        //             dp[i][j] = (dp[i][j] + dp[i - 1][k]) % (1000000000 + 7);
        //         }
        //         // at i has and the num in arr1 is j
        //         // dp[i][j] = dp[i][j-d]
        //     }
        // }
        // 0 overflow here
        return accumulate(dp[n].begin(), dp[n].end(), 0ll) % (1000000000 + 7);
        function<long long(int, int, int)> dfs = [&](int cur, int premax, int premin) -> long long
        {
            if (dp[cur][premax])
            {
                return dp[cur][premax];
            }
            if (cur == n - 1)
            {
                // premax to nums[cur]
                //  i in [premax, nums[cur]]
                // nums[cur]-i <premin
                // i>nums[cur]-premin
                //
                return max(nums[cur] - max(premax, nums[cur] - premin) + 1ll, 0ll);
            }
            else
            {
                long long ans = 0;
                for (int i = nums[cur]; i >= premax && nums[cur] - i <= premin; i--)
                {
                    ans += dfs(cur + 1, i, nums[cur] - i);
                }
                return dp[cur][premax] = ans % (1000000000 + 7);
            }
        };
        return dfs(0, 0, 10001) % (1000000000 + 7);
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 2};
    // vector<int> nums = {40, 40, 40, 40, 41, 42, 43, 44, 45, 45};
    // vector<int> nums = {50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    cout << s.countOfPairs(nums) << endl;
    return 0;
}
/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [40,91,187,256,334,337,694,749,782,833]\n
// @lcpr case=end

 */
