/*
 * @lc app=leetcode.cn id=3192 lang=cpp
 * @lcpr version=30204
 *
 * [3192] 使二进制数组全部等于 1 的最少操作次数 II
 *
 * https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/
 *
 * algorithms
 * Medium (72.80%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 8.2K
 * Testcase Example:  '[0,1,1,0,1]'
 *
 * 给你一个二进制数组 nums 。
 *
 * 你可以对数组执行以下操作 任意 次（也可以 0 次）：
 *
 *
 * 选择数组中 任意 一个下标 i ，并将从下标 i 开始一直到数组末尾 所有 元素 反转 。
 *
 *
 * 反转 一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。
 *
 * 请你返回将 nums 中所有元素变为 1 的 最少 操作次数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [0,1,1,0,1]
 *
 * 输出：4
 *
 * 解释：
 * 我们可以执行以下操作：
 *
 *
 * 选择下标 i = 1 执行操作，得到 nums = [0,0,0,1,0] 。
 * 选择下标 i = 0 执行操作，得到 nums = [1,1,1,0,1] 。
 * 选择下标 i = 4 执行操作，得到 nums = [1,1,1,0,0] 。
 * 选择下标 i = 3 执行操作，得到 nums = [1,1,1,1,1] 。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,0,0,0]
 *
 * 输出：1
 *
 * 解释：
 * 我们可以执行以下操作：
 *
 *
 * 选择下标 i = 1 执行操作，得到 nums = [1,1,1,1] 。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 1
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
    int minOperations(vector<int> nums)
    {
        int has = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = has % 2 == 1 ? !nums[i] : nums[i];
            if (cur == 0)
            {
                ++has;
            }
        }
        return has;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout<<s.minOperations({0, 1, 1, 0, 1});
    return 0;

}
/*
// @lcpr case=start
// [0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0]\n
// @lcpr case=end

 */
