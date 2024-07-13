/*
 * @lc app=leetcode.cn id=2970 lang=cpp
 * @lcpr version=30204
 *
 * [2970] 统计移除递增子数组的数目 I
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
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool flag = true;
                for (int l = 0; l + 1 < i; l++)
                {
                    if (nums[l + 1] <= nums[l])
                    {
                        flag = false;
                    }
                }
                if (i - 1 >= 0 && j + 1 < n && nums[i - 1] >= nums[j + 1])
                {
                    flag = false;
                }
                for (int l = j + 1; l + 1 < n; l++)
                {
                    if (nums[l + 1] <= nums[l])
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    ++ans;
                }
            }
        }
        return ans;
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
