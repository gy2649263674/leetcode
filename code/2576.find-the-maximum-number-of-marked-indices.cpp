/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 * @lcpr version=30204
 *
 * [2576] 求出最多标记下标
 *
 * https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/description/
 *
 * algorithms
 * Medium (39.79%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 26K
 * Testcase Example:  '[3,5,2,4]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 *
 * 一开始，所有下标都没有被标记。你可以执行以下操作任意次：
 *
 *
 * 选择两个 互不相同且未标记 的下标 i 和 j ，满足 2 * nums[i] <= nums[j] ，标记下标 i 和 j 。
 *
 *
 * 请你执行上述操作任意次，返回 nums 中最多可以标记的下标数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,5,2,4]
 * 输出：2
 * 解释：第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] <= nums[1] ，标记下标 2 和 1 。
 * 没有其他更多可执行的操作，所以答案为 2 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [9,2,5,4]
 * 输出：4
 * 解释：第一次操作中，选择 i = 3 和 j = 0 ，操作可以执行的原因是 2 * nums[3] <= nums[0] ，标记下标 3 和 0 。
 * 第二次操作中，选择 i = 1 和 j = 2 ，操作可以执行的原因是 2 * nums[1] <= nums[2] ，标记下标 1 和 2 。
 * 没有其他更多可执行的操作，所以答案为 4 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [7,6,8]
 * 输出：0
 * 解释：没有任何可以执行的操作，所以答案为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
    int maxNumOfMarkedIndices(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n / 2;
        int ans = 0;
        // use the bionary to prove the greedy
        //  if m is able then m-1 is able and it must be the pre m num 
        // which is the most esay to reach the target
        // while there most be n/2 pair 
        // then direct try if n/2 is able or not and check it use 2 pointer
        // if two paired which are all in the [0,n/2] only makes it harder to pair 
        
        while (r < n&&l<n/2)
        {
            if (nums[r] >= nums[l] * 2)
            {
                ++l;
                ans += 2;
            }
            // always use; keep the smallest
            // which has the min request
            ++r;
        }
        return ans;
    }
    int maxNumOfMarkedIndices2(vector<int> nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int var : nums)
        {
            cout << var << " ";
        }
        cout << endl;

        return 0;
        priority_queue<int, vector<int>, less<int>> aux;
        //  every time try to enum the max val can use to be the w double
        // 2 3 4 5
        int r = n - 1;

        int ans = 0;
        // dp[i] the tot in pre
        // dp[i][2]
        // dp[i][0] = max(dp[i-1][1],i-1,0)
        // dp[i][1] = dp[j(lower(nums[i]/2))][0]0
        while (r >= 0)
        {
            if (aux.empty())
            {
                aux.push(nums[r]);
            }
            else
            {
                int mm = aux.top();
                if (nums[r] * 2 <= mm)
                {
                    aux.pop();
                    ans += 2;
                }
                else
                {
                    aux.push(nums[r]);
                }
            }
            --r;
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.maxNumOfMarkedIndices({42, 83, 48, 10, 24, 55, 9, 100, 10, 17, 17, 99, 51, 32, 16, 98, 99, 31, 28, 68, 71, 14, 64, 29, 15, 40}) << endl;
    return 0;
}
/*
// @lcpr case=start
// [3,5,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [9,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,8]\n
// @lcpr case=end

 */
// 9 10 10 14 15 16 17 17
// 24 28 29 31 32 40 42 48
// 51 55 64 68 71 83 98 99 99 100