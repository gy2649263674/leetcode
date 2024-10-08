/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (46.21%)
 * Likes:    2795
 * Dislikes: 0
 * Total Accepted:    453K
 * Total Submissions: 978.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= heights.length <=10^5
 * 0 <= heights[i] <= 10^4
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
// #include<multimap>
#include <set>
// #include<bits/stdc++.h>
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // enum every ele as the height and the wodth should be the dis of l and r that firstly small then the currrent val ;
        


    }
    int largestRectangleArea1(vector<int> &heights)
    {
        int n = heights.size();
        int l = 0, r = n - 1;
        int ml = heights[0], mr = heights.back();
        deque<int> aux;
        for (int i = 0; i < n; i++)
        {
            while (!aux.empty() && heights[aux.back()] > heights[i])
            {
                aux.push_back(i);
            }
        }
        // if ml<mr
        // ans = ml*d
        // try to let ml increase
        // if let r-- then the ans must small ten the current ans
        multiset<int> st(heights.begin(), heights.end());
        int ans = 0;
        while (l <= r)
        {
            int minval = *st.begin();
            ans = max(ans, minval * (r - l + 1));
            if (heights[l] < heights[r])
            {
                st.erase(st.find(heights[l]));
                ++l;
            }
            else
            {
                st.erase(st.find(heights[r]));
                --r;
            }
            // while (!aux.empty() && aux.front() < l || aux.front() > r)
            // {
            //     aux.pop_front();
            // }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
