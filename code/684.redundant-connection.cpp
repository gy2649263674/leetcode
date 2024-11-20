/*
 * @lc app=leetcode.cn id=684 lang=cpp
 * @lcpr version=30204
 *
 * [684] 冗余连接
 *
 * https://leetcode.cn/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (68.14%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    124.3K
 * Total Submissions: 182.2K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 *
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 *
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
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
#include <numeric>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> edges)
    {
        int mxind = 0;
        for (auto edge : edges)
            mxind = max({mxind, edge[0], edge[1]});
        vector<int> pa(1001);
        function<int(int)> find = [&](int a) -> int
        {
            return pa[a] = pa[a] == a ? a : find(pa[a]);
        };
        auto merge = [&](int a, int b)
        {
            pa[find(a)] = find(b);
        };
        auto check = [&](int ex) -> bool
        {
            for (int i = 0; i < edges.size(); i++)
            {
                if (i != ex)
                {
                    merge(edges[i][0], edges[i][1]);
                }
            }
            int f = find(1);
            for (int i = 1; i <= mxind; i++)
            {
                if (find(i) != f)
                {
                    return false;
                }
            }
            return true;
        };
        for (int i = edges.size() - 1; i >= 0; i--)
        {
            iota(pa.begin(), pa.end(), 0);
            if (check(i))
            {
                return edges[i];
            }
        }
        return {};
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    s.findRedundantConnection({{1, 2}, {1, 3}, {2, 3}});
    return 0;
}
/*
// @lcpr case=start
// [[1,2], [1,3], [2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
// @lcpr case=end

 */

// {
//     // function<int>dfs
//     // bool mp[1001][1001];
//     vector<vector<int>> mp(1001);
//     vector<bool> vis(1001);
//     deque<pair<int, int>> aux;
//     for (auto edge : edges)
//     {
//         mp[edge[0]].push_back(edge[1]);
//         mp[edge[1]].push_back(edge[0]);
//     }
//     function<bool(int, int)>
//         dfs = [&](int cur, int pre) -> bool
//     {
//         if (vis[cur])
//         {
//             return true;
//         }
//         vis[cur] = true;
//         for (auto to : mp[cur])
//         {
//             if (to != pre)
//             {
//                 aux.push_back({cur, to});
//                 vis[to] = true;
//                 if (dfs(to, cur))
//                 {
//                     return true;
//                 }
//                 else
//                 {
//                     vis[to] = false;
//                     aux.pop_back();
//                 }
//             }
//         }
//         return false;
//     };
//     dfs(1, -1);
//     int mx = 0;
//     for (auto p : aux)
//     {
//         int cnt = 0;
//         for (auto _p : edges)
//         {
//             cnt++;
//             if (_p[0] == p.first && _p[1] == p.second || _p[0] == p.second && _p[1] == p.first)
//             {
//                 mx = max(mx, cnt);
//                 break;
//                 // mx = max(mx, ans);
//             }
//         }
//     }
//     return edges[mx];
// }