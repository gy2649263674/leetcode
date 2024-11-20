/*
 * @lc app=leetcode.cn id=3255 lang=cpp
 * @lcpr version=30204
 *
 * [3255] 长度为 K 的子数组的能量值 II
 *
 * https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/description/
 *
 * algorithms
 * Medium (46.77%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 13.4K
 * Testcase Example:  '[1,2,3,4,3,2,5]\n3'
 *
 * 给你一个长度为 n 的整数数组 nums 和一个正整数 k 。
 *
 * 一个数组的 能量值 定义为：
 *
 *
 * 如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
 * 否则为 -1 。
 *
 *
 * 你需要求出 nums 中所有长度为 k 的 子数组 的能量值。
 *
 * 请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)]
 * 的能量值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,4,3,2,5], k = 3
 *
 * 输出：[3,4,-1,-1,-1]
 *
 * 解释：
 *
 * nums 中总共有 5 个长度为 3 的子数组：
 *
 *
 * [1, 2, 3] 中最大元素为 3 。
 * [2, 3, 4] 中最大元素为 4 。
 * [3, 4, 3] 中元素 不是 连续的。
 * [4, 3, 2] 中元素 不是 上升的。
 * [3, 2, 5] 中元素 不是 连续的。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,2,2,2], k = 4
 *
 * 输出：[-1,-1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [3,2,3,2,3,2], k = 2
 *
 * 输出：[-1,3,-1,3,-1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n == nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= n
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
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        int tail = nums[0];
        int l = 0, r = 0;
        vector<int> ans;
        while (l + k - 1 < n)
        {
            while (r - l + 1 < k && r + 1 < n && nums[r + 1] - nums[r] == 1)
            {
                ++r;
            }
            ans.push_back(r - l + 1 == k ? nums[r] : -1);
            l++;
            r = max(r, l);
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    auto ar = s.resultsArray({1, 7, 8}, 2);
    for (auto r : ar)
    {
        cout << r << endl;
    }
    return 0;
}
/*
// @lcpr case=start
// [1,2,3,4,3,2,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,2,3,2]\n2\n
// @lcpr case=end

 */
