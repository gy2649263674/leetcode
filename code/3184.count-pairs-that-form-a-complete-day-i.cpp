/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 * @lcpr version=30204
 *
 * [3184] 构成整天的下标对数目 I
 *
 * https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-i/description/
 *
 * algorithms
 * Easy (79.70%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 26K
 * Testcase Example:  '[12,12,30,24,24]'
 *
 * 给你一个整数数组 hours，表示以 小时 为单位的时间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天
 * 的下标对 i, j 的数目。
 *
 * 整天 定义为时间持续时间是 24 小时的 整数倍 。
 *
 * 例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： hours = [12,12,30,24,24]
 *
 * 输出： 2
 *
 * 解释：
 *
 * 构成整天的下标对分别是 (0, 1) 和 (3, 4)。
 *
 *
 * 示例 2：
 *
 *
 * 输入： hours = [72,48,24,3]
 *
 * 输出： 3
 *
 * 解释：
 *
 * 构成整天的下标对分别是 (0, 1)、(0, 2) 和 (1, 2)。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= hours.length <= 100
 * 1 <= hours[i] <= 10^9
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
    int countCompleteDayPairs(vector<int> &hours)
    {
        {
            int st[24] = {0};
            long long ans = 0;
            for (int cur : hours)
            {
                for (int i = 0; i < 24; i++)
                {
                    ans += (i + cur) % 24 == 0 ? st[i] : 0;
                }
                ++st[cur % 24];
            }
            return ans;
            // for()
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [12,12,30,24,24]\n
// @lcpr case=end

// @lcpr case=start
// [72,48,24,3]\n
// @lcpr case=end

 */
