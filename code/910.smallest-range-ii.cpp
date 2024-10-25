/*
 * @lc app=leetcode.cn id=910 lang=cpp
 * @lcpr version=30204
 *
 * [910] 最小差值 II
 *
 * https://leetcode.cn/problems/smallest-range-ii/description/
 *
 * algorithms
 * Medium (36.58%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 37.7K
 * Testcase Example:  '[1]\n0'
 *
 * 给你一个整数数组 nums，和一个整数 k 。
 *
 * 对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成  nums[i] + k 或 nums[i] - k 。
 *
 * nums 的 分数 是 nums 中最大元素和最小元素的差值。
 *
 * 在更改每个下标对应的值之后，返回 nums 的最小 分数 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1], k = 0
 * 输出：0
 * 解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,10], k = 2
 * 输出：6
 * 解释：将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,3,6], k = 3
 * 输出：3
 * 解释：将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^4
 * 0 <= k <= 10^4
 *
 *
 */

// class Solution
// {
// public:
//     int smallestRangeII(vector<int> nums, int k)
//     {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         if (n == 1)
//         {
//             return 0;
//         }
//         int ans = INT_MAX;
//         for (int i = 0; i < n; i++)
//         {
//             // enum every one to be the biggest
//             if (upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k) == nums.end())
//             {
//                 // first to add k is the smallest 0 or 1
//                 // first to sub k is the smallest -> i+1
//                 // nums[j]+k>nums[i]+k

//                 int tmp = INT_MAX / 2;
//                 int j = 0;
//                 for (; j < n && nums[j] + k <= nums[i] + k; j++)
//                 {
//                     if (j != i)
//                         tmp = min(tmp, nums[j] + k <= nums[i] + k ? nums[j] + k : tmp);
//                 }
//                 for (; j < n && nums[j] - k <= nums[i] + k; j++)
//                 {
//                     if (j != i)
//                         tmp = min(tmp, nums[j] - k <= nums[i] + k ? nums[j] - k : tmp);

//                 }
//                 ans = min(ans, (nums[i] + k) - tmp);
//                 // ans = max(ans, tmp);
//             }
//             if (upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) == nums.end())
//             {
//                 int tmp = INT_MAX / 2;
//                 int j = 0;
//                 for (; j < n && nums[j] + k <= nums[i] - k; j++)
//                 {
//                     if (j != i)
//                         tmp = min(tmp, nums[j] + k <= nums[i] - k ? nums[j] + k : tmp);

//                 }
//                 for (; j < n && nums[j] - k <= nums[i] - k; j++)
//                 {
//                     if (j != i)
//                         tmp = min(tmp, nums[j] - k <= nums[i] + k ? nums[j] - k : tmp);

//                 }
//                 ans = min(ans, (nums[i] - k) - tmp);
//                 // ans = max(ans, tmp);
//             }
//         }
//         return ans;
//     }
// };
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
#define INCREMENT(x) ((x) + 1)
class Solution
{
public:
    int smallestRangeII(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (k == 0)
        {
            return nums.back() - nums.front();
        }
        if (n == 1)
        {
            return 0;
        }
        int ans = INT_MAX;
        // when i = 0
        // the all later should be sub
        ans = nums[0] + k - (nums[1] - k);
        ans = min(ans, nums[n - 1] + k - nums[0] - k);
        // when the nums[n-1]-k
        // the min should be
        int t1 = INT_MAX;
        auto l = upper_bound(nums.begin(), nums.end(), nums[n - 1] - 2 * k);
        if (l == nums.begin())
        {
            // t1 = nums[n - 1] - nums[0];
            t1 = nums[0] - k;
        }
        else
        {
            t1 = min(nums[0] + k, *l - k);
        }
        for (int i = 1; i < n - 1; i++)
        {
            // enum every one to be the biggest
            if (upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k) == nums.end())
            {
                // first to add k is the smallest 0 or 1
                // first to sub k is the smallest -> i+1
                // nums[j]+k>nums[i]+k
                int tmp = INT_MAX / 2;
                // the val add k will exceed the cur+k
                auto x = lower_bound(nums.begin(), nums.end(), nums[i] + k);
                int minval = min({nums[0] + k, nums[i - 1] + k, nums[i + 1] - k});
                // if i!=0
                int j = 0;
                tmp = min(tmp, nums[j] + k <= nums[i] + k ? nums[j] + k : tmp);
                tmp = min(tmp, nums[j] - k <= nums[i] + k ? nums[j] - k : tmp);
                ans = min(ans, (nums[i] + k) - tmp);
                // ans = max(ans, tmp);
            }
            if (upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) == nums.end())
            {
                int tmp = INT_MAX / 2;
                int j = 0;
                tmp = min(tmp, nums[j] + k <= nums[i] - k ? nums[j] + k : tmp);
                tmp = min(tmp, nums[j] - k <= nums[i] + k ? nums[j] - k : tmp);
                ans = min(ans, (nums[i] - k) - tmp);
                // ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.smallestRangeII({2, 7, 2}, 1);
    return 0;
}
/*
// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0,10]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,1,10]\n4\n
// @lcpr case=end

 */
