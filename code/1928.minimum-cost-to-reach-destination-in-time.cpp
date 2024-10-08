/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 * @lcpr version=30204
 *
 * [1928] 规定时间内到达终点的最小花费
 *
 * https://leetcode.cn/problems/minimum-cost-to-reach-destination-in-time/description/
 *
 * algorithms
 * Hard (45.89%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    11.9K
 * Total Submissions: 22.7K
 * Testcase Example:  '30\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]'
 *
 * 一个国家有 n 个城市，城市编号为 0 到 n - 1 ，题目保证 所有城市 都由双向道路 连接在一起 。道路由二维整数数组 edges 表示，其中
 * edges[i] = [xi, yi, timei] 表示城市 xi 和 yi 之间有一条双向道路，耗费时间为 timei
 * 分钟。两个城市之间可能会有多条耗费时间不同的道路，但是不会有道路两头连接着同一座城市。
 *
 * 每次经过一个城市时，你需要付通行费。通行费用一个长度为 n 且下标从 0 开始的整数数组 passingFees 表示，其中
 * passingFees[j] 是你经过城市 j 需要支付的费用。
 *
 * 一开始，你在城市 0 ，你想要在 maxTime 分钟以内 （包含 maxTime 分钟）到达城市 n - 1 。旅行的 费用 为你经过的所有城市
 * 通行费之和 （包括 起点和终点城市的通行费）。
 *
 * 给你 maxTime，edges 和 passingFees ，请你返回完成旅行的 最小费用 ，如果无法在 maxTime 分钟以内完成旅行，请你返回
 * -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：maxTime = 30, edges =
 * [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees =
 * [5,1,2,20,20,3]
 * 输出：11
 * 解释：最优路径为 0 -> 1 -> 2 -> 5 ，总共需要耗费 30 分钟，需要支付 11 的通行费。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：maxTime = 29, edges =
 * [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees =
 * [5,1,2,20,20,3]
 * 输出：48
 * 解释：最优路径为 0 -> 3 -> 4 -> 5 ，总共需要耗费 26 分钟，需要支付 48 的通行费。
 * 你不能选择路径 0 -> 1 -> 2 -> 5 ，因为这条路径耗费的时间太长。
 *
 *
 * 示例 3：
 *
 * 输入：maxTime = 25, edges =
 * [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees =
 * [5,1,2,20,20,3]
 * 输出：-1
 * 解释：无法在 25 分钟以内从城市 0 到达城市 5 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= maxTime <= 1000
 * n == passingFees.length
 * 2 <= n <= 1000
 * n - 1 <= edges.length <= 1000
 * 0 <= xi, yi <= n - 1
 * 1 <= timei <= 1000
 * 1 <= passingFees[j] <= 1000 
 * 图中两个节点之间可能有多条路径。
 * 图中不含有自环。
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
// @lcpr-template-end
// @lc code=start
#define pii pair<int, int>
class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &fees)
    {

        int n = fees.size();
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INT_MAX / 2));
        // from 0 to j cost t time the min cost is dp[j][t]?
        dp[0][0] = fees[0];
        // fill(fees.begin(),fees.end)
        for (int t = 0; t < maxTime + 1; t++)
        {
            dp[t][0] = fees[0];
            for (auto &it : edges)
            {
                int from = it[0];
                int to = it[1];
                int co = it[2];
                if (co <= t)
                {
                    dp[t][to] = min(dp[t][to], dp[t - co][from] + fees[to]);
                    dp[t][from] = min(dp[t][from], dp[t - co][to] + fees[from]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= maxTime; i++)
        {
            ans = min(ans, dp[i][n - 1]);
        }
        return ans >= INT_MAX / 2 ? -1 : ans;

        /*
// @lcpr case=start
// 30\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start
// 29\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start
// 25\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start

500\n[[36,1,2],[8,41,29],[47,7,50],[33,17,6],[47,37,28],[3,38,2],[27,2,4],[11,30,17],[32,35,48],[12,1,32],[7,27,6],[7,4,25],[15,8,11],[2,17,50],[7,45,14],[40,8,48],[4,22,5],[28,23,20],[20,27,49],[26,34,13],[17,47,40],[47,4,32],[0,30,21],[30,29,8],[15,3,38],[4,3,39],[22,16,46],[47,10,13],[42,23,30],[34,0,13],[12,25,11],[5,2,1],[7,36,48],[44,11,7],[20,47,9],[42,37,49],[42,4,46],[1,39,26],[14,5,25],[32,17,16],[22,7,25],[3,22,36],[49,8,46],[16,20,6],[16,21,32],[26,43,35],[43,19,7],[0,2,35],[35,37,25],[25,48,46],[9,4,28],[24,5,21],[37,30,7],[14,16,40],[25,35,26],[49,38,1],[24,13,36],[27,6,8],[10,3,37],[23,13,26],[31,21,19],[28,1,48],[15,21,18],[17,7,40],[33,12,24],[44,28,11],[46,43,37],[1,26,47],[3,46,17],[28,22,20],[8,34,3],[18,6,2],[38,16,30],[17,38,20],[12,10,26],[21,40,18],[19,2,25],[31,28,25],[41,8,5],[9,3,14],[5,0,8],[3,36,25],[32,23,37],[2,1,11],[49,25,18],[33,24,48],[42,28,25],[4,40,47],[37,11,23],[37,46,45],[9,42,35],[34,1,19],[17,2,17],[15,17,13],[33,20,1],[40,34,13],[25,21,40],[40,9,41],[47,15,41],[3,10,20],[33,35,47],[22,8,37],[35,40,34],[29,38,34],[37,15,17],[28,39,43],[24,37,28],[16,24,8],[37,46,10],[4,44,34],[41,17,20],[25,40,45],[15,18,30],[48,25,16],[16,11,7],[16,1,34],[19,44,11],[37,7,14],[11,49,5],[29,32,3],[17,32,7],[39,18,10],[25,14,9],[1,0,36],[7,28,46],[48,13,44],[46,31,27],[11,0,32],[30,32,24],[27,15,33],[20,19,43],[16,8,6],[28,21,43],[13,33,14],[3,2,45],[20,6,27],[35,17,23],[38,46,48],[46,48,5],[45,43,20],[49,24,14],[45,34,28],[10,32,46],[10,37,29],[39,21,46],[34,25,22],[6,11,3],[0,34,19],[6,20,3],[33,0,44],[4,6,15],[35,13,22],[29,41,20],[6,4,33],[45,15,43],[33,46,40],[45,34,23],[19,27,33],[19,2,9],[21,2,29],[14,25,15],[37,44,34],[16,41,41],[18,3,18],[46,32,13],[43,48,47],[28,13,39],[26,47,46],[13,28,46],[26,19,32],[13,11,41],[17,43,13],[39,47,15],[48,13,37],[29,17,27],[35,33,29],[24,37,19],[43,22,49],[40,5,33],[23,24,34],[38,13,12],[8,2,10],[43,16,44],[2,31,46],[48,10,15],[16,31,11],[3,33,9],[33,10,9],[41,18,41],[41,47,46],[10,44,6],[27,38,45],[42,28,2],[19,9,30],[21,32,26],[48,41,10],[28,42,9],[31,7,42],[0,17,41],[1,0,25],[25,20,32]]\n[45,308,835,819,667,547,322,428,306,327,362,280,334,767,767,533,514,9,539,125,153,325,937,745,334,804,336,587,71,463,287,492,466,935,373,950,760,994,390,836,911,948,81,945,593,821,58,138,50,537]
// @lcpr case=end

 */

        // vector<vector<pii>> edges2(n);
        // vector<map<int, int>> dp(n);
        // vector<map<int, bool>> vis(n);
        // for (auto it : edges)
        // {
        //     edges2[it[0]].push_back({it[2], it[1]});
        //     edges2[it[1]].push_back({it[2], it[0]});
        //     // cost to
        // }
        // function<int(int, int, int)> dfs = [&](int cur, int t, int c) -> int
        // {
        //     if (t > maxTime)
        //     {
        //         return INT_MAX;
        //     }
        //     if (cur == n - 1)
        //     {
        //         if (dp[n - 1].count(t))
        //         {
        //             return dp[n - 1][t] = min(dp[n - 1][t], c);
        //         }
        //         else
        //         {
        //             return dp[n - 1][t] = c;
        //         }
        //     }
        //     if (dp[cur].count(t))
        //     {
        //         return dp[cur][t];
        //     }
        //     else
        //     {
        //         vis[cur][t] = true;
        //         int tmp = INT_MAX;
        //         for (auto [cost, to] : edges2[cur])
        //         {
        //             if (vis[to][t + cost] == false)
        //                 tmp = min(dfs(to, t + cost, c + fees[to]), tmp);
        //         }
        //         return dp[cur][t] = min(tmp, dp[cur][t]);
        //     }
        // };
        // dfs(0, 0, fees[0]);
        // int ans = INT_MAX;
        // for (auto [_, co] : dp[n - 1])
        // {
        //     ans = min(ans, co);
        // }
        // return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end
/*
// @lcpr case=start
// 30\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start
// 29\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start
// 25\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start

500\n[[36,1,2],[8,41,29],[47,7,50],[33,17,6],[47,37,28],[3,38,2],[27,2,4],[11,30,17],[32,35,48],[12,1,32],[7,27,6],[7,4,25],[15,8,11],[2,17,50],[7,45,14],[40,8,48],[4,22,5],[28,23,20],[20,27,49],[26,34,13],[17,47,40],[47,4,32],[0,30,21],[30,29,8],[15,3,38],[4,3,39],[22,16,46],[47,10,13],[42,23,30],[34,0,13],[12,25,11],[5,2,1],[7,36,48],[44,11,7],[20,47,9],[42,37,49],[42,4,46],[1,39,26],[14,5,25],[32,17,16],[22,7,25],[3,22,36],[49,8,46],[16,20,6],[16,21,32],[26,43,35],[43,19,7],[0,2,35],[35,37,25],[25,48,46],[9,4,28],[24,5,21],[37,30,7],[14,16,40],[25,35,26],[49,38,1],[24,13,36],[27,6,8],[10,3,37],[23,13,26],[31,21,19],[28,1,48],[15,21,18],[17,7,40],[33,12,24],[44,28,11],[46,43,37],[1,26,47],[3,46,17],[28,22,20],[8,34,3],[18,6,2],[38,16,30],[17,38,20],[12,10,26],[21,40,18],[19,2,25],[31,28,25],[41,8,5],[9,3,14],[5,0,8],[3,36,25],[32,23,37],[2,1,11],[49,25,18],[33,24,48],[42,28,25],[4,40,47],[37,11,23],[37,46,45],[9,42,35],[34,1,19],[17,2,17],[15,17,13],[33,20,1],[40,34,13],[25,21,40],[40,9,41],[47,15,41],[3,10,20],[33,35,47],[22,8,37],[35,40,34],[29,38,34],[37,15,17],[28,39,43],[24,37,28],[16,24,8],[37,46,10],[4,44,34],[41,17,20],[25,40,45],[15,18,30],[48,25,16],[16,11,7],[16,1,34],[19,44,11],[37,7,14],[11,49,5],[29,32,3],[17,32,7],[39,18,10],[25,14,9],[1,0,36],[7,28,46],[48,13,44],[46,31,27],[11,0,32],[30,32,24],[27,15,33],[20,19,43],[16,8,6],[28,21,43],[13,33,14],[3,2,45],[20,6,27],[35,17,23],[38,46,48],[46,48,5],[45,43,20],[49,24,14],[45,34,28],[10,32,46],[10,37,29],[39,21,46],[34,25,22],[6,11,3],[0,34,19],[6,20,3],[33,0,44],[4,6,15],[35,13,22],[29,41,20],[6,4,33],[45,15,43],[33,46,40],[45,34,23],[19,27,33],[19,2,9],[21,2,29],[14,25,15],[37,44,34],[16,41,41],[18,3,18],[46,32,13],[43,48,47],[28,13,39],[26,47,46],[13,28,46],[26,19,32],[13,11,41],[17,43,13],[39,47,15],[48,13,37],[29,17,27],[35,33,29],[24,37,19],[43,22,49],[40,5,33],[23,24,34],[38,13,12],[8,2,10],[43,16,44],[2,31,46],[48,10,15],[16,31,11],[3,33,9],[33,10,9],[41,18,41],[41,47,46],[10,44,6],[27,38,45],[42,28,2],[19,9,30],[21,32,26],[48,41,10],[28,42,9],[31,7,42],[0,17,41],[1,0,25],[25,20,32]]\n[45,308,835,819,667,547,322,428,306,327,362,280,334,767,767,533,514,9,539,125,153,325,937,745,334,804,336,587,71,463,287,492,466,935,373,950,760,994,390,836,911,948,81,945,593,821,58,138,50,537]
// @lcpr case=end

 */
