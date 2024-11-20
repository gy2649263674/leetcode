/*
 * @lc app=leetcode.cn id=3244 lang=cpp
 * @lcpr version=30204
 *
 * [3244] 新增道路查询后的最短距离 II
 *
 * https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/description/
 *
 * algorithms
 * Hard (33.07%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 9.6K
 * Testcase Example:  '5\n[[2,4],[0,2],[0,4]]'
 *
 * 给你一个整数 n 和一个二维整数数组 queries。
 *
 * 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。
 *
 * queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1
 * 的最短路径的长度。
 *
 * 所有查询中不会存在两个查询都满足 queries[i][0] < queries[j][0] < queries[i][1] <
 * queries[j][1]。
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
 * 提示:
 *
 *
 * 3 <= n <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] < queries[i][1] < n
 * 1 < queries[i][1] - queries[i][0]
 * 查询中不存在重复的道路。
 * 不存在两个查询都满足 i != j 且 queries[i][0] < queries[j][0] < queries[i][1] <
 * queries[j][1]。
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
class Solution
{
public:
    vector<int> shortestDistanceAfterQueries2(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<int> nex(n);
        iota(nex.begin(), nex.end(), 1);
        int dis = n - 1;
        for (auto q : queries)
        {
            int r = q[1], l = q[0];
            if (nex[l] && nex[l] < r)
            {
                for (int i = nex[l]; i < r;)
                {
                    int tmp = nex[i];
                    nex[i] = 0;
                    --dis;
                    // the circles is used mainly for reduce the dis
                    i = tmp;
                }
                nex[l] = r;
            }
            ans.push_back(dis);
        }
        return ans;
    }
    vector<int> shortestDistanceAfterQueries1(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        set<int> st1;
        for (int i = 0; i < n - 1; i++)
        {
            st1.insert(i);
        }
        for (auto q : queries)
        {
            // auto able = st.lower_bound(q);
            auto it = st1.upper_bound(q[0]);
            while (it != st1.end() && *it < q[1])
            {
                st1.erase(it);
                it = st1.upper_bound(q[0]);
            }
            ans.push_back(st1.size());
        }
        return ans;
    }

    vector<int> violate(int n, vector<vector<int>> &queries)
    {
        vector<int> nex(n);
        iota(nex.begin(), nex.end(), 1);
        function<int()> sim = [&]()
        {
            int cur = 0, res = 0;
            while (cur < n)
            {
                cur = nex[cur];
                ++res;
            }
            return res - 1;
        };
        vector<int> ans;
        for (auto &q : queries)
        {
            nex[q[0]] = max(q[1], nex[q[0]]);
            ans.push_back(sim());
        }
        return ans;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> fa(n);
        iota(fa.begin(), fa.end(), 0);
        vector<int> ans;
        function<int(int)> find = [&](int x) -> int
        {
            int pa = x;
            while (fa[pa] != pa)
            {
                pa = fa[pa];
            }
            while (x != pa)
            {
                int tmp = fa[x];
                fa[x] = pa;
                x = tmp;
            }
            return pa;
        };
        int dis = n - 1;
        for (auto q : queries)
        {
            // add a edge between q[0] and q[1]
            //[l,r] fa[i] = r;
            int r = q[1] - 1, l = q[0];
            int pa = find(r);
            for (int i = find(l); i < r; i = find(i + 1))
            {
                --dis;
                fa[i] = pa;
            }
            ans.push_back(dis);
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    int n = 5;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    auto ans = s.shortestDistanceAfterQueries(n, queries);
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
