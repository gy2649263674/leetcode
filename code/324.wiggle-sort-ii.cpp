/*
 * @lc app=leetcode.cn id=324 lang=cpp
 * @lcpr version=30204
 *
 * [324] 摆动排序 II
 *
 * https://leetcode.cn/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (41.15%)
 * Likes:    600
 * Dislikes: 0
 * Total Accepted:    71.2K
 * Total Submissions: 172.9K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * 给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
 *
 * 你可以假设所有输入数组都可以得到满足题目要求的结果。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,5,1,1,6,4]
 * 输出：[1,6,1,5,1,4]
 * 解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,3,2,2,3,1]
 * 输出：[2,3,1,3,1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * 0 <= nums[i] <= 5000
 * 题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
 *
 *
 *
 *
 * 进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
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
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        int x = n / 2;
        // enum the from back
        // if current pair is <i-x,i>
        // then the nextt pair is <i-x-1,i-1>
        // which ensure thath i-(i-x-1)>x to ensure [i]!= [i-x-1]
        // if enum from 0->n
        // then the next pair is <i-x+1,i+1>
        // can't ensure [i]!= [i-x+1]
        // the diff is small than x  which may cause same value
        // the nex
        for (int i = 0, j = n - 1; i < n; i += 2, j--)
        {
            ans[i] = nums[j - x];
            if (i + 1 < n)
            {
                ans[i + 1] = nums[j];
            }
        }
        nums = ans;
        return;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,5,1,1,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,2,3,1]\n
// @lcpr case=end

 */
