/*
 * @lc app=leetcode.cn id=871 lang=cpp
 * @lcpr version=30204
 *
 * [871] 最低加油次数
 *
 * https://leetcode.cn/problems/minimum-number-of-refueling-stops/description/
 *
 * algorithms
 * Hard (43.70%)
 * Likes:    450
 * Dislikes: 0
 * Total Accepted:    39.6K
 * Total Submissions: 89.5K
 * Testcase Example:  '1\n1\n[]'
 *
 * 汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
 *
 * 沿途有加油站，用数组 stations 表示。其中 stations[i] = [positioni, fueli] 表示第 i
 * 个加油站位于出发位置东面 positioni 英里处，并且有 fueli 升汽油。
 *
 * 假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1
 * 升汽油。当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。
 *
 * 为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。
 *
 * 注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。
 *
 *
 *
 * 示例 1：
 *
 * 输入：target = 1, startFuel = 1, stations = []
 * 输出：0
 * 解释：可以在不加油的情况下到达目的地。
 *
 *
 * 示例 2：
 *
 * 输入：target = 100, startFuel = 1, stations = [[10,100]]
 * 输出：-1
 * 解释：无法抵达目的地，甚至无法到达第一个加油站。
 *
 *
 * 示例 3：
 *
 * 输入：target = 100, startFuel = 10, stations =
 * [[10,60],[20,30],[30,30],[60,40]]
 * 输出：2
 * 解释：
 * 出发时有 10 升燃料。
 * 开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
 * 然后，从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
 * 并将汽油从 10 升加到 50 升。然后开车抵达目的地。
 * 沿途在两个加油站停靠，所以返回 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target, startFuel <= 10^9
 * 0 <= stations.length <= 500
 * 1 <= positioni < positioni+1 < target
 * 1 <= fueli < 10^9
 *
 *
 */
// int n = stations.size();
// vector<map<long long, int>> mp(n);
// function<int(int, long long, long long)> dfs = [&](int cur, long long fuel, long long pos) -> int
// {
//     if (pos >= target)
//         return 0;
//     else if (fuel < 0)
//     {
//         return INT_MAX / 2;
//     }
//     if (mp[cur].count(fuel))
//         return mp[cur][fuel];
//     if (cur + 1 < stations.size())
//     {
//         int add = INT_MAX / 2;
//         if (stations[cur + 1][0] <= pos + fuel)
//         {
//             add = dfs(cur + 1, fuel - stations[cur + 1][0] + pos + stations[cur + 1][1], stations[cur + 1][0]) + 1;
//         }
//         return min(add,
//                    dfs(cur + 1, fuel - (stations[cur + 1][0] - pos), stations[cur + 1][0]));
//     }
//     else
//     {
//         return fuel + pos >= target ? 0 : INT_MAX / 2;
//     }
// };
// int ans = dfs(-1, startFuel, 0);
// return ans == INT_MAX / 2 ? -1 : ans;
// dp[i] = dp[]
// for (int i = 0; i < n; i++)
// {
// enum the last position to add oil;
/*for (int j = 0; j < n; j++)
{
    if (dp[i] >= stations[j][0])
    {
        // only enum the times of add oil and the last station can't ensure that the stations will only be used for once
        dp[i + 1] = max(dp[i + 1], dp[i] + stations[j][1]);
    }
}
}
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
class Solution
{
public:
    int minRefuelStops(int target, int sf, vector<vector<int>> &stations)
    {
        priority_queue<int, deque<int>, less<int>> aux;
        long long reach = 0;
        long long pos = sf, n = stations.size(), ans = 0;
        while ((reach < n && pos >= stations[reach][0]) || (aux.empty() == false))
        {
            while (reach < n && stations[reach][0] <= pos)
            {
                aux.push(stations[reach][1]);
                reach++;
            }
            if (pos >= target)
            {
                return ans;
            }
            else
            {
                pos += aux.top();
                aux.pop();  
                ++ans;
            }
        }
        return pos >= target ? ans : -1;
    }
    int minRefuelStops1(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        vector<long long> dp(n + 1);
        // dp[i] represent the  longest distance than can reach eq the most fuel can reach
        // after add oil for i times;
        // actually is has i stations and can add j oil
        // has i items and cam choose j from it
        dp[0] = startFuel;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                // has passed i statioins thenmost can add j oil;
                // j should be in (0,i);
                // add j+1 times
                // j+1 should be the distance after add oil
                // 0  to i will be i+1 stations
                // and then j should be in (0,i)
                // considering the j+1 times come from the staton[i]
                if (dp[j] >= stations[i][0])
                {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            if (dp[i] >= target)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 100\n1\n[[10,100]]\n
// @lcpr case=end

// @lcpr case=start
// 100\n10\n[[10,60],[20,30],[30,30],[60,40]]\n
// @lcpr case=end

 */
