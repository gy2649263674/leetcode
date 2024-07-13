/*
 * @lc app=leetcode.cn id=2972 lang=cpp
 * @lcpr version=30204
 *
 * [2972] 统计移除递增子数组的数目 II
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
    long long incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < n && nums[l] < nums[l + 1])
        {
            ++l;
        }
        if (l == n)
        {
            return (n + 1) * n / 2;
        }
        while (r >= 1 && nums[r - 1] <= nums[r])
        {
            --r;
        }
        int ans = 0;
        for(int i = 0;i<l;i++)
        {
            ans
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [8,7,6,6]\n
// @lcpr case=end

 */
