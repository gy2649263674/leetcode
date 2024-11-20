/*
 * @lc app=leetcode.cn id=685 lang=cpp
 * @lcpr version=30204
 *
 * [685] 冗余连接 II
 *
 * https://leetcode.cn/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (42.30%)
 * Likes:    443
 * Dislikes: 0
 * Total Accepted:    43.9K
 * Total Submissions: 101.2K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的 有向
 * 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 *
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n
 * 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 *
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是
 * vi 的一个父节点。
 *
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 *
 *
 * 示例 2：
 *
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ui, vi <= n
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>> edges)
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
            pa[find(b)] = find(a);
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
    vector<vector<int>> v = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
    cout << s.findRedundantDirectedConnection(v) << endl;
    return 0;
}
/*
// @lcpr case=start
//[[2,1],[3,1],[4,2],[1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,1],[1,5]]\n
// @lcpr case=end

 */
