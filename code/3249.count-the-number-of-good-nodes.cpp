/*
 * @lc app=leetcode.cn id=3249 lang=cpp
 * @lcpr version=30204
 *
 * [3249] 统计好节点的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-good-nodes/description/
 *
 * algorithms
 * Medium (52.42%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 17.1K
 * Testcase Example:  '[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]'
 *
 * 现有一棵 无向 树，树中包含 n 个节点，按从 0 到 n - 1 标记。树的根节点是节点 0 。给你一个长度为 n - 1 的二维整数数组
 * edges，其中 edges[i] = [ai, bi] 表示树中节点 ai 与节点 bi 之间存在一条边。
 *
 * 如果一个节点的所有子节点为根的 子树 包含的节点数相同，则认为该节点是一个 好节点。
 *
 * 返回给定树中 好节点 的数量。
 *
 * 子树 指的是一个节点以及它所有后代节点构成的一棵树。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
 *
 * 输出：7
 *
 * 说明：
 *
 * 树的所有节点都是好节点。
 *
 *
 * 示例 2：
 *
 *
 * 输入：edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]
 *
 * 输出：6
 *
 * 说明：
 *
 * 树中有 6 个好节点。上图中已将这些节点着色。
 *
 *
 * 示例 3：
 *
 *
 * 输入：edges =
 * [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]
 *
 * 输出：12
 *
 * 解释：
 *
 * 除了节点 9 以外其他所有节点都是好节点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * 输入确保 edges 总表示一棵有效的树。
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
    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<bool> suns(n + 1);
        vector<bool> vis(n + 1);
        // set<pair<int, int>> st;
        vector<vector<int>> mp(n);
        for (auto &e : edges)
        {
            // st.insert({e[0], e[1]});
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        function<int(int)> cal = [&](int root) -> int
        {
            vis[root] = true;
            int sum = 0, pre = -1;
            bool flag = true;
            for (int i = 0; i < mp[root].size(); i++)
            {
                int cur = 0;
                if (!vis[mp[root][i]])
                {
                    cur = cal(mp[root][i]);
                    if (pre != cur && pre != -1)
                    {
                        flag = false;
                    }
                    pre = cur;
                }
                sum += cur;
            }
            suns[root] = flag;
            return sum + 1;
        };
        cal(0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (suns[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]\n
// @lcpr case=end

 */
