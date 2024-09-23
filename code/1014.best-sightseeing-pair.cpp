/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 * @lcpr version=30204
 *
 * [1014] 最佳观光组合
 *
 * https://leetcode.cn/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (57.40%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    66.4K
 * Total Submissions: 115.1K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * 给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
 * 
 * 一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去
 * 它们两者之间的距离。
 * 
 * 返回一对观光景点能取得的最高分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：values = [8,1,5,2,6]
 * 输出：11
 * 解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
 * 
 * 
 * 示例 2：
 * 
 * 输入：values = [1,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= values.length <= 5 * 10^4
 * 1 <= values[i] <= 1000
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
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // vector<int> sm(values.size(), 0);
        int n = values.size();
        int mx = values[0];
        int ans = 0;
        // doesn't to store the vals;
        for(int i = 1;i<n;i++)
        {
            ans = max(ans,mx+values[i]-i);
            mx  = max(mx,values[i]+i);
        }
        return ans;
        // vector<int> bg(values.size(), 0);
        // bg.back() = values.back()-n+1;
        // for(int i  = n-2;i>=0;i--)
        // {
        //     bg[i] = max(values[i]-i,bg[i+1]);
        // }
        // int ans = 0;
        // for(int i = 0;i<n-1;i++)
        // {
        //     ans = max(ans,values[i]+i+bg[i+1]);
        // }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,1,5,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

