/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 * @lcpr version=30204
 *
 * [1547] 切棍子的最小成本
 *
 * https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/description/
 *
 * algorithms
 * Hard (58.82%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 21.1K
 * Testcase Example:  '7\n[1,3,4,5]'
 *
 * 有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6 的棍子可以标记如下：
 *
 *
 *
 * 给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。
 *
 * 你可以按顺序完成切割，也可以根据需要更改切割的顺序。
 *
 *
 * 每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。
 *
 * 返回切棍子的 最小总成本 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 7, cuts = [1,3,4,5]
 * 输出：16
 * 解释：按 [1, 3, 4, 5] 的顺序切割的情况如下所示：
 *
 * 第一次切割长度为 7 的棍子，成本为 7 。第二次切割长度为 6 的棍子（即第一次切割得到的第二根棍子），第三次切割为长度 4 的棍子，最后切割长度为
 * 3 的棍子。总成本为 7 + 6 + 4 + 3 = 20 。
 * 而将切割顺序重新排列为 [3, 5, 1, 4] 后，总成本 = 16（如示例图中 7 + 4 + 3 + 2 = 16）。
 *
 *
 * 示例 2：
 *
 * 输入：n = 9, cuts = [5,6,1,4,2]
 * 输出：22
 * 解释：如果按给定的顺序切割，则总成本为 25 。总成本 <= 25 的切割顺序很多，例如，[4, 6, 5, 2, 1] 的总成本 =
 * 22，是所有可能方案中成本最小的。
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^6
 * 1 <= cuts.length <= min(n - 1, 100)
 * 1 <= cuts[i] <= n - 1
 * cuts 数组中的所有整数都 互不相同
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
#include <bits/stdc++.h>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int minCost0(int n, vector<int> &cuts)
    {
        deque<int> dq(cuts.begin(), cuts.end());
        sort(dq.begin(), dq.end());
        dq.push_back(n);
        dq.push_front(0);
        int si = dq.size();
        map<pair<int, int>, int> dp;
        function<int(int, int)> dfs = [&](int l, int r) -> int
        {
            if (dp.count({l, r}))
                return dp[{l, r}];
            if (l + 1 == r)
                return 0;
            int ans = INT_MAX / 2;
            for (int i = l + 1; i < r; i++)
            {
                ans = min(ans, dfs(l, i) + dfs(i, r) + dq[r] - dq[l]);
            }
            return dp[{l, r}] = ans;
        };
        return dfs(0, si - 1);
    }
    int minCost(int n, vector<int> &cuts)
    {
        deque<int> dq(cuts.begin(), cuts.end());
        sort(dq.begin(), dq.end());
        dq.push_back(n);
        dq.push_front(0);
        int si = dq.size();
        priority_queue<pair<int, int>> aux;
        map<int, int> mp;
        int ans = 0;
        for (int i = 2; i < si; i++)
        {
            mp[dq[i]] = dq[i] - dq[i - 1];
            aux.push({(dq[i] - dq[i - 1]), dq[i]});
        }
        set<int> erased;
        while (mp.empty() == false)
        {
            int cur = aux.top().second;
            if (erased.contains(cur))
            {
                aux.pop();
                continue;
            }
            else
            {
                auto it = mp.find(cur);
                advance(it, -1);
                erased.insert(it->first);
                it = mp.find(cur);
                advance(it, -1);
                auto pre = it;
                advance(it, 2);
                auto suf = it;
                if (it != mp.end())
                {
                    aux.push({suf->first - pre->first, suf->first});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[1,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// 9\n[5,6,1,4,2]\n
// @lcpr case=end

 */
