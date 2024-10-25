/*
 * @lc app=leetcode.cn id=1884 lang=cpp
 * @lcpr version=30204
 *
 * [1884] 鸡蛋掉落-两枚鸡蛋
 *
 * https://leetcode.cn/problems/egg-drop-with-2-eggs-and-n-floors/description/
 *
 * algorithms
 * Medium (71.88%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 16.1K
 * Testcase Example:  '2'
 *
 * 给你 2 枚相同 的鸡蛋，和一栋从第 1 层到第 n 层共有 n 层楼的建筑。
 *
 * 已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都 会碎 ，从 f 楼层或比它低 的楼层落下的鸡蛋都 不会碎 。
 *
 * 每次操作，你可以取一枚 没有碎 的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <=
 * n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。
 *
 * 请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 * 解释：我们可以将第一枚鸡蛋从 1 楼扔下，然后将第二枚从 2 楼扔下。
 * 如果第一枚鸡蛋碎了，可知 f = 0；
 * 如果第二枚鸡蛋碎了，但第一枚没碎，可知 f = 1；
 * 否则，当两个鸡蛋都没碎时，可知 f = 2。
 *
 *
 * 示例 2：
 *
 * 输入：n = 100
 * 输出：14
 * 解释：
 * 一种最优的策略是：
 * - 将第一枚鸡蛋从 9 楼扔下。如果碎了，那么 f 在 0 和 8 之间。将第二枚从 1 楼扔下，然后每扔一次上一层楼，在 8 次内找到 f
 * 。总操作次数 = 1 + 8 = 9 。
 * - 如果第一枚鸡蛋没有碎，那么再把第一枚鸡蛋从 22 层扔下。如果碎了，那么 f 在 9 和 21 之间。将第二枚鸡蛋从 10
 * 楼扔下，然后每扔一次上一层楼，在 12 次内找到 f 。总操作次数 = 2 + 12 = 14 。
 * - 如果第一枚鸡蛋没有再次碎掉，则按照类似的方法从 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99 和 100
 * 楼分别扔下第一枚鸡蛋。
 * 不管结果如何，最多需要扔 14 次来确定 f 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
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
    int twoEggDrop(int n)
    {
        int ans = n;
        for (int i = n; i >= 0; i--)
        {
            // if assume the ans is i then the way to ensure that the most able way to get the ans is to check 
            // if ((i + i - k) * (k + 1) / 2 >= n)
            if ((i + 1.0 / 2) * (i + 1.0 / 2) >= 2 * n)
            {
                ans = min(ans, i);
            }
            else
            {
                break;
            }
        }

        return ans;
    }
    void dp()
    {
        // if break at kth then 
        // must enum from 1 to k 
        // else doesbn't break then then  ans must be in (k,i]
        // dp[i] = dp[i-k]
        // dp[i] = max(dp[i-k])
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 100\n
// @lcpr case=end

 */
