/*
 * @lc app=leetcode.cn id=218 lang=cpp
 * @lcpr version=30204
 *
 * [218] 天际线问题
 *
 * https://leetcode.cn/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (55.46%)
 * Likes:    855
 * Dislikes: 0
 * Total Accepted:    56.7K
 * Total Submissions: 102.2K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * 城市的 天际线 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回 由这些建筑物形成的 天际线 。
 *
 * 每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti]
 * 表示：
 *
 *
 * lefti 是第 i 座建筑物左边缘的 x 坐标。
 * righti 是第 i 座建筑物右边缘的 x 坐标。
 * heighti 是第 i 座建筑物的高度。
 *
 *
 * 你可以假设所有的建筑都是完美的长方形，在高度为 0 的绝对平坦的表面上。
 *
 * 天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序
 * 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0
 * ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
 *
 * 注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...]
 * 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
 *
 *
 *
 * 示例 1：
 *
 * 输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * 输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * 解释：
 * 图 A 显示输入的所有建筑物的位置和高度，
 * 图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
 *
 * 示例 2：
 *
 * 输入：buildings = [[0,2,3],[2,5,3]]
 * 输出：[[0,3],[5,0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= buildings.length <= 10^4
 * 0 <= lefti < righti <= 2^31 - 1
 * 1 <= heighti <= 2^31 - 1
 * buildings 按 lefti 非递减排序
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
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> tree;
    // record the h of the interval
    // update the l r to x
    // how
    void mod(int l, int r, int h)
    {
        return;
    }
    vector<vector<int>> violent(vector<vector<int>> &bui)
    {
        int n = bui.size();
        deque<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int h = bui[i][2];
            for (int j = 0; j < n; j++)
            {
                // /
                if (bui[j][0] <= bui[i][0] && bui[j][1] > bui[i][0])
                {
                    h = max(h, bui[j][2]);
                }
            }
            ans.push_back({bui[i][0], h});
            h = 0;
            for (int j = 0; j < n; j++)
            {
                // must extened to the right
                // the bui[j][0]<=bui[i][1] can't ensure the bui[j][1] biggger then the bui[i][1]
                if (bui[j][0] <= bui[i][1] && bui[j][1] > bui[i][1])
                {
                    h = max(h, bui[j][2]);
                }
            }
            ans.push_back({bui[i][1], h});
        }
        sort(ans.begin(), ans.end());
        vector<vector<int>> res;
        res.push_back(ans.front());
        for (const auto &var : ans)
        {
            if (res.back()[1] != ans.front()[1])
            {
                res.push_back(ans.front());
            }
            ans.pop_front();
        }
        return res;
    }
    vector<vector<int>> opt(vector<vector<int>> &bd)
    {
        vector<int> po;
        sort(bd.begin(), bd.end());
        set<int> tmp;
        // po.insert(po.begin(), bd.begin(), bd.end());
        for (int i = 0; i < bd.size(); i++)
        {
            // tmp.insert(bd[i][0]);
            // tmp.insert(bd[i][1]);
            po.push_back(bd[i][0]);
            po.push_back(bd[i][1]);
        }
        // for (auto var : tmp)
        // {
        //     po.push_back(var);
        // }
        sort(po.begin(), po.end());
        priority_queue<pair<int, int>, deque<pair<int, int>>, less<pair<int, int>>> aux;
        int j = 0;
        vector<vector<int>> ans;
        int pre = -1;
        for (int i = 0; i < po.size(); i++)
        {
            while (j < bd.size() && bd[j][0] <= po[i])
            {
                aux.push({bd[j][2], bd[j][1]});
                ++j;
            }
            // if the top can be push then the l must small then current val
            // then if the right if bigger the current val then the building is able
            while (!aux.empty() && aux.top().second <= po[i])
            {
                aux.pop();
            }
            if (aux.empty() && pre != 0)
            {
                ans.push_back({po[i], 0});
                pre = 0;
            }
            else if (!aux.empty()&&pre != aux.top().first)
            {
                ans.push_back({po[i], aux.top().first});
                pre = aux.top().first;
            }
            // because the same ele 
        }
        return ans;
    }
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        return opt(buildings);
        // return violent(buildings);
        // int n = buildings.size();
        // tree = vector<int>(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     mod(buildings[i][0], buildings[i][1], buildings[i][2]);
        // }
        // for (int i = 0)
    }
};
// @lc code=end
int main(void)
{
    // 1 2 0
    // 1 2 1
    Solution s;
    vector<vector<int>> v({{1, 2, 1}, {1, 2, 2}, {1, 2, 3}});
    auto ans = s.getSkyline(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
// @lcpr case=start
// [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2,3],[2,5,3]]\n
// @lcpr case=end

 */
