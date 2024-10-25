/*
 * @lc app=leetcode.cn id=3193 lang=cpp
 * @lcpr version=30204
 *
 * [3193] 统计逆序对的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-inversions/description/
 *
 * algorithms
 * Hard (44.86%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 5.6K
 * Testcase Example:  '3\n[[2,2],[0,0]]'
 *
 * 给你一个整数 n 和一个二维数组 requirements ，其中 requirements[i] = [endi, cnti]
 * 表示这个要求中的末尾下标和 逆序对 的数目。
 *
 * 整数数组 nums 中一个下标对 (i, j) 如果满足以下条件，那么它们被称为一个 逆序对 ：
 *
 *
 * i < j 且 nums[i] > nums[j]
 *
 *
 * 请你返回 [0, 1, 2, ..., n - 1] 的 排列 perm 的数目，满足对 所有 的 requirements[i] 都有
 * perm[0..endi] 恰好有 cnti 个逆序对。
 *
 * 由于答案可能会很大，将它对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, requirements = [[2,2],[0,0]]
 *
 * 输出：2
 *
 * 解释：
 *
 * 两个排列为：
 *
 *
 * [2, 0, 1]
 *
 *
 * 前缀 [2, 0, 1] 的逆序对为 (0, 1) 和 (0, 2) 。
 * 前缀 [2] 的逆序对数目为 0 个。
 *
 *
 * [1, 2, 0]
 *
 * 前缀 [1, 2, 0] 的逆序对为 (0, 2) 和 (1, 2) 。
 * 前缀 [1] 的逆序对数目为 0 个。
 *
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, requirements = [[2,2],[1,1],[0,0]]
 *
 * 输出：1
 *
 * 解释：
 *
 * 唯一满足要求的排列是 [2, 0, 1] ：
 *
 *
 * 前缀 [2, 0, 1] 的逆序对为 (0, 1) 和 (0, 2) 。
 * 前缀 [2, 0] 的逆序对为 (0, 1) 。
 * 前缀 [2] 的逆序对数目为 0 。
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 2, requirements = [[0,0],[1,0]]
 *
 * 输出：1
 *
 * 解释：
 *
 * 唯一满足要求的排列为 [0, 1] ：
 *
 *
 * 前缀 [0] 的逆序对数目为 0 。
 * 前缀 [0, 1] 的逆序对为 (0, 1) 。
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 300
 * 1 <= requirements.length <= n
 * requirements[i] = [endi, cnti]
 * 0 <= endi <= n - 1
 * 0 <= cnti <= 400
 * 输入保证至少有一个 i 满足 endi == n - 1 。
 * 输入保证所有的 endi 互不相同。
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
    int numberOfPermutations(int n, vector<vector<int>> &req)
    {
        // int dp[i][j] = dp[i-1][]
        // add i into the arr has i way add [0,i]  to the ans
        // vector<vector<int>> dp = vector(n, vector<int>(n * n, 0));
        vector<int> li(n, -1);
        for (auto var : req)
        {
            li[var[0]] = var[1];
        }
        int dp[401][400] = {0};
        function<int(int, int)> solve = [&](int i, int j) -> int
        {
            if (j < 0 || i < 0)
            {
                return 0;
            }
            if (n == 0)
            {
                return j == 0 ? 1 : 0;
            }
            if (dp[i][j])
            {
                return dp[i][j];
            }
            else
            {
                int tmp = 0;
                if (li[i] != -1)
                {
                    // has limit
                    return dp[i][j] = solve(i - 1, j - li[i]);
                }
                else
                {
                    // how many pair caused by the nth index
                    // because the current i is the bigest so just
                    // now is i then has i+1 idgit totally 0
                    // there are still i digit in the front
                    for (int x = 0; x <= min(i, j); x++)
                    {
                        tmp += solve(i - 1, j - x);
                    }
                    return dp[i][j] = tmp;
                }
            }
        };
        return solve(n - 1, li[n - 1]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n[[2,2],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[2,2],[1,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0],[1,0]]\n
// @lcpr case=end

 */
