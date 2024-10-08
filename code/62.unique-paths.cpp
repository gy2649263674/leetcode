/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30204
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (68.66%)
 * Likes:    2097
 * Dislikes: 0
 * Total Accepted:    860.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 示例 1：
 *
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 示例 2：
 *
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 *
 *
 * 示例 3：
 *
 * 输入：m = 7, n = 3
 * 输出：28
 *
 *
 * 示例 4：
 *
 * 输入：m = 3, n = 3
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int com(int n, int k)
    {
        long long  ans = 1;
        for(int i = 1;i<= k;i++)
        {
            ans= ans* (n-i+1ll)/i;
        }
        return ans;
    }
    int uniquePaths(int m, int n)
    {
        return com(m+n-2,min(m-1,n-1));
        // c(m+n) m
        // ax == 1
        // ax+by == 1
        int dp[110][110] = {0};
        dp[m - 1][n - 1] = 1;
        // for (int i = m - 1; i >= 0; i--)
        // {
        //     dp[i][n - 1] = 1;
        // }
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     dp[m - 1][i] = 1;
        // }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] += dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */
