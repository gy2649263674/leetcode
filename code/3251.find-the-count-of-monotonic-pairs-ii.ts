/*
 * @lc app=leetcode.cn id=3251 lang=typescript
 * @lcpr version=30204
 *
 * [3251] 单调数组对的数目 II
 *
 * https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/description/
 *
 * algorithms
 * Hard (47.42%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 14.4K
 * Testcase Example:  '[2,3,2]'
 *
 * 给你一个长度为 n 的 正 整数数组 nums 。
 * 
 * 如果两个 非负 整数数组 (arr1, arr2) 满足以下条件，我们称它们是 单调 数组对：
 * 
 * 
 * 两个数组的长度都是 n 。
 * arr1 是单调 非递减 的，换句话说 arr1[0] <= arr1[1] <= ... <= arr1[n - 1] 。
 * arr2 是单调 非递增 的，换句话说 arr2[0] >= arr2[1] >= ... >= arr2[n - 1] 。
 * 对于所有的 0 <= i <= n - 1 都有 arr1[i] + arr2[i] == nums[i] 。
 * 
 * 
 * 请你返回所有 单调 数组对的数目。
 * 
 * 由于答案可能很大，请你将它对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 单调数组对包括：
 * 
 * 
 * ([0, 1, 1], [2, 2, 1])
 * ([0, 1, 2], [2, 2, 0])
 * ([0, 2, 2], [2, 1, 0])
 * ([1, 2, 2], [1, 1, 0])
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,5,5,5]
 * 
 * 输出：126
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == nums.length <= 2000
 * 1 <= nums[i] <= 1000
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
function countOfPairs(nums: number[]): number {
    let n: number = nums.length;
    function dfs(index: number, premax: number, premin: number): number {
        if (index === n - 1) {
            // cur in [premax,nums[index]]
            // n- cur in [0,premin]
            return Math.max(nums[index] - premax + 1, 0);
        }
        else {
            let ans: number = 0;
            for (let i = premax; i <= nums[index] && nums[index] - i <= premin; i++) {
                let tmp = dfs(index + 1, i, nums[index] - i);
                if (tmp === 0) {
                    break;
                }
                ans += tmp;
            }
            return ans;
        }
    };
    return dfs(0, 0, 10001);
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

