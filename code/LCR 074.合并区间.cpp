/*
 * @lc app=leetcode.cn id=LCR 074 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 074] 合并区间
 *
 * https://leetcode.cn/problems/SsGoHC/description/
 *
 * algorithms
 * Medium (55.89%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    38.1K
 * Total Submissions: 68.2K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 *
 *
 *
 * 示例 1：
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 *
 *
 * 注意：本题与主站 56 题相同： https://leetcode-cn.com/problems/merge-intervals/
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
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &nums)
    {
        deque<vector<int>> aux;
        sort(nums.begin(), nums.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        for (auto var : nums)
        {
            if (aux.empty())
            {
                aux.push_back({var[0], var[1]});
            }
            else
            {
                if (aux.back()[1] >= var[0])
                {
                    vector<int> tmp = {aux.back()[0], max(var[1], aux.back()[1])};
                    aux.pop_back();
                    aux.push_back(tmp);
                }
                else
                {
                    aux.push_back({var[0], var[1]});
                }
            }
        }
        return vector<vector<int>>(aux.begin(), aux.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */
