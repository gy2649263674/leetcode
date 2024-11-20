/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 * @lcpr version=30204
 *
 * [3243] 新增道路查询后的最短距离 I
 *
 * https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/description/
 *
 * algorithms
 * Medium (41.14%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    15.9K
 * Total Submissions: 29.2K
 * Testcase Example:  '5\n[[2,4],[0,2],[0,4]]'
 *
 * 给你一个整数 n 和一个二维整数数组 queries。
 *
 * 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。
 *
 * queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1
 * 的最短路径的长度。
 *
 * 返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1
 * 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 5, queries = [[2, 4], [0, 2], [0, 4]]
 *
 * 输出： [3, 2, 1]
 *
 * 解释：
 *
 *
 *
 * 新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。
 *
 *
 *
 * 新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。
 *
 *
 *
 * 新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 4, queries = [[0, 3], [0, 2]]
 *
 * 输出： [1, 1]
 *
 * 解释：
 *
 *
 *
 * 新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。
 *
 *
 *
 * 新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= n <= 500
 * 1 <= queries.length <= 500
 * queries[i].length == 2
 * 0 <= queries[i][0] < queries[i][1] < n
 * 1 < queries[i][1] - queries[i][0]
 * 查询中没有重复的道路。
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
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> mp(n, vector<int>());
        // iota(mp.begin(), mp.end(), vector<);
        for (int i = 0; i < n; i++)
        {
            mp[i].push_back(i + 1);
        }
        function<int()> bfs = [&]() -> int
        {
            // for (auto)
            vector<bool> vis(n, false);
            queue<int> q;
            int res = 0;
            q.push(0);
            while (q.empty() == false)
            {
                ++res;
                int sz = q.size();
                for (int i = 0; i < sz; i++)
                {
                    if (q.front() == n - 1)
                    {
                        return res-1;
                    }
                    for (auto v : mp[q.front()])
                    {
                        if (vis[v] == false)
                        {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                    q.pop();
                }
            }
            return res;
        };
        vector<int> ans;
        for (auto &q : queries)
        {
            mp[q[0]].push_back(q[1]);
            ans.push_back(bfs());
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution sol;
    int n = 5;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    auto ans = sol.shortestDistanceAfterQueries(n, queries);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
/*
// @lcpr case=start
// 5\n[[2, 4], [0, 2], [0, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0, 3], [0, 2]]\n
// @lcpr case=end

 */
