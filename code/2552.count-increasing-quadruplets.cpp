/*
 * @lc app=leetcode.cn id=2552 lang=cpp
 * @lcpr version=30204
 *
 * [2552] 统计上升四元组
 *
 * https://leetcode.cn/problems/count-increasing-quadruplets/description/
 *
 * algorithms
 * Hard (40.34%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 12.3K
 * Testcase Example:  '[1,3,2,4,5]'
 *
 * 给你一个长度为 n 下标从 0 开始的整数数组 nums ，它包含 1 到 n 的所有数字，请你返回上升四元组的数目。
 *
 * 如果一个四元组 (i, j, k, l) 满足以下条件，我们称它是上升的：
 *
 *
 * 0 <= i < j < k < l < n 且
 * nums[i] < nums[k] < nums[j] < nums[l] 。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,2,4,5]
 * 输出：2
 * 解释：
 * - 当 i = 0 ，j = 1 ，k = 2 且 l = 3 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
 * - 当 i = 0 ，j = 1 ，k = 2 且 l = 4 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
 * 没有其他的四元组，所以我们返回 2 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4]
 * 输出：0
 * 解释：只存在一个四元组 i = 0 ，j = 1 ，k = 2 ，l = 3 ，但是 nums[j] < nums[k] ，所以我们返回 0
 * 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 4 <= nums.length <= 4000
 * 1 <= nums[i] <= nums.length
 * nums 中所有数字 互不相同 ，nums 是一个排列。
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
#include <bits/stdc++.h>
class Solution
{
public:
    long long countQuadruplets(vector<int> &nums)
    {
        // for()
        // dp[i]  start with nums[i]  and increase
        int n = nums.size();
        long long pre[4001] = {0};
        // i j k l
        long long ans = 0;
        for (int j = 0; j < n; j++)
        {
            int suf = 0;
            for (int k = n - 1; k >= j + 1; k--)
            {
                if (nums[k] > nums[j])
                {
                    ++suf;
                }
                else
                {

                    // 0all i before j and nums[i]<nums[k] doesn;t include nums[j]
                    // nums[j] is the 2nd big so the suf is linked to the nums[j]
                    ans += pre[nums[k]] * suf;
                    // here should small than k because k is the 2nd smallest
                }
            }
            for (int t = nums[j] + 1; t <= n; t++)
            {
                ++pre[t];
            }
            // end with i and increase pair
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */
