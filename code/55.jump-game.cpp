/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30204
 *
 * [55] 跳跃游戏
 *
 * https://leetcode.cn/problems/jump-game/description/
 *
 * algorithms
 * Medium (43.31%)
 * Likes:    2851
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 * 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [3,2,1,0,4]
 * 输出：false
 * 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
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
    bool canJump(vector<int> nums)
    {
        if (nums.size() == 1)
            return true;
        int i = 0;
        for (; i < nums.size();)
        {
            int next = i;
            int nexti = i;
            for (int j = 0; j <= nums[i] && i + j < nums.size(); j++)
            {
                if (next < i + j + nums[i + j])
                {
                    nexti = i + j;
                    next = i + j + nums[i + j];
                }
            }

            if (next == i)
            {
                return i >= nums.size() - 1 ? true : false;
            }
            if (i == nexti)
            {
                i += nums[i];
                continue;
            }
            i = nexti;
        }
        return i >= nums.size() - 1;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.canJump({5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0});
    return 0;
}
/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */
