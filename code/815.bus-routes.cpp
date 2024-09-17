/*

        // function<int(int)> dfs = [&](int cur) -> int
        // {
        //     // can reach
        //     if (cur == target)
        //     {
        //         return 0;
        //     }
        //     if (dp[cur] != -1)
        //     {
        //         return dp[cur];
        //     }
        //     int ans = 1e9;
        //     for (auto id : in[cur])
        //     {
        //         for (auto ables : routes[id])
        //         {
        //             for (int able : ables)
        //             {
        //                 ans = min(ans, dfs(able) + 1);
        //             }
        //         }
        //     }
        //     return dp[cur] = ans;
        // };
        // return dp[source];
 * @lc app=leetcode.cn id=815 lang=cpp
 * @lcpr version=30204
 *
 * [815] 公交路线
 *
 * https://leetcode.cn/problems/bus-routes/description/
 *
 * algorithms
 * Hard (44.46%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    43.4K
 * Total Submissions: 95.9K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * 给你一个数组 routes ，表示一系列公交线路，其中每个 routes[i] 表示一条公交线路，第 i 辆公交车将会在上面循环行驶。
 *
 *
 * 例如，路线 routes[0] = [1, 5, 7] 表示第 0 辆公交车会一直按序列 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1
 * -> ... 这样的车站路线行驶。
 *
 *
 * 现在从 source 车站出发（初始时不在公交车上），要前往 target 车站。 期间仅可乘坐公交车。
 *
 * 求出 最少乘坐的公交车数量 。如果不可能到达终点车站，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：routes = [[1,2,7],[3,6,7]], source = 1, target = 6
 * 输出：2
 * 解释：最优策略是先乘坐第一辆公交车到达车站 7 , 然后换乘第二辆公交车到车站 6 。
 *
 *
 * 示例 2：
 *
 * 输入：routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target =
 * 12
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5
 * routes[i] 中的所有值 互不相同
 * sum(routes[i].length) <= 10^5
 * 0 <= routes[i][j] < 10^6
 * 0 <= source, target < 10^6
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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
    {
        vector<int> dp(1e6, -1);
        vector<bool> vis(1e6, false);
        unordered_map<int, vector<int>> in;
        int t = 0;
        for (auto route : routes)
        {
            for (int sta : route)
            {
                in[sta].push_back(t);
            }
            t++;
        }
        queue<pair<int, int>> aux;
        aux.push({source, 0});
        dp[source] = 0;
        if (source == target)
        {
            return 0;
        }
        while (!aux.empty())
        {
            auto cur = aux.front().first;
            int floor = aux.front().second;
            for (int var : in[cur])
            {
                if (vis[var])
                {
                    continue;
                }
                else
                {
                    vis[var] = true;
                }
                for (int nex : routes[var])
                {
                    if (dp[nex] == -1)
                    {
                        aux.push({nex, floor + 1});
                        dp[nex] = floor + 1;
                    }
                    if (nex == target)
                    {
                        return floor + 1;
                    }
                }
            }
            aux.pop();
        }
        return -1;

        // @lcpr case=start
        // [[1,2,7],[3,6,7]]\n1\n6\n
        // @lcpr case=end

        // @lcpr case=start
        // [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12\n
        // @lcpr case=end
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout<<s.numBusesToDestination({{1, 2, 7}, {3, 6, 7}},
                            1,
                            6);
    return 0;
}
/*
// @lcpr case=start
// [[1,2,7],[3,6,7]]\n1\n6\n
// @lcpr case=end

// @lcpr case=start
// [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12\n
// @lcpr case=end

 */
