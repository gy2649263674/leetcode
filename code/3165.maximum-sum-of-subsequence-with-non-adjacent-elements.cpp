/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 * @lcpr version=30204
 *
 * [3165] 不包含相邻元素的子序列的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/
 *
 * algorithms
 * Hard (27.33%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 18.9K
 * Testcase Example:  '[3,5,9]\n[[1,-2],[0,-3]]'
 *
 * 给你一个整数数组 nums 和一个二维数组 queries，其中 queries[i] = [posi, xi]。
 *
 * 对于每个查询 i，首先将 nums[posi] 设置为 xi，然后计算查询 i 的答案，该答案为 nums 中 不包含相邻元素 的 子序列 的 最大
 * 和。
 *
 * 返回所有查询的答案之和。
 *
 * 由于最终答案可能非常大，返回其对 10^9 + 7 取余 的结果。
 *
 * 子序列 是指从另一个数组中删除一些或不删除元素而不改变剩余元素顺序得到的数组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,5,9], queries = [[1,-2],[0,-3]]
 *
 * 输出：21
 *
 * 解释：
 * 执行第 1 个查询后，nums = [3,-2,9]，不包含相邻元素的子序列的最大和为 3 + 9 = 12。
 * 执行第 2 个查询后，nums = [-3,-2,9]，不包含相邻元素的子序列的最大和为 9 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,-1], queries = [[0,-5]]
 *
 * 输出：0
 *
 * 解释：
 * 执行第 1 个查询后，nums = [-5,-1]，不包含相邻元素的子序列的最大和为 0（选择空子序列）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -10^5 <= nums[i] <= 10^5
 * 1 <= queries.length <= 5 * 10^4
 * queries[i] == [posi, xi]
 * 0 <= posi <= nums.length - 1
 * -10^5 <= xi <= 10^5
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
class Solution
{
public:
    vector<int> sum;
    void build()
    {

    }
    int query(int ind, bool usel, bool user)
    {

    }
    
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        sum.resize(n);
        // for()
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,5,9]\n[[1,-2],[0,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [0,-1]\n[[0,-5]]\n
// @lcpr case=end

 */
