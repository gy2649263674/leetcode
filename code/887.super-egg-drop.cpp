/*
 * @lc app=leetcode.cn id=887 lang=cpp
 * @lcpr version=30204
 *
 * [887] 鸡蛋掉落
 *
 * https://leetcode.cn/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (31.27%)
 * Likes:    1029
 * Dislikes: 0
 * Total Accepted:    89.5K
 * Total Submissions: 282K
 * Testcase Example:  '1\n2'
 *
 * 给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
 *
 * 已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。
 *
 * 每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <=
 * n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。
 *
 * 请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
 *
 *
 * 示例 1：
 *
 * 输入：k = 1, n = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
 * 如果它没碎，那么肯定能得出 f = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
 *
 *
 * 示例 2：
 *
 * 输入：k = 2, n = 6
 * 输出：3
 *
 *
 * 示例 3：
 *
 * 输入：k = 3, n = 14
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= 100
 * 1 <= n <= 10^4
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
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
    int dfs(int k, int n)
    {
        if (k == 0)
        {
            return n == 0 ? 0 : INT_MAX / 2;
        }
        if (n == 0)
        {
            return 0;
        }
        else
        {

            //
        }
    }
    int superEggDrop(int k, int n)
    {
        int dp[k + 1][n + 1] = {0};
        for (int i = 1; i < k; i++)
        {
            // if the egg doesn't break
            // enuym the x floor
            // k egg and j floor
            // dp[k][i] = max(dp[k][i-x],dp[k-1][x-1]
            for (int j = 0; j <= n; j++)
            {
                // just enum where the kth egg is used
                for (int x = 0; x <= j; x++)
                {
                    dp[i][j] = max(dp[i][j - x], dp[i - 1][x - 1]) + 1;
                }
            }
            // for(int j = 0;j<)
        }
        return dp[][]
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.superEggDrop(3, 14);
    return 0;
}
/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n
// @lcpr case=end
+-+
// @lcpr case=start
// 3\n14\n
// @lcpr case=end

 */
