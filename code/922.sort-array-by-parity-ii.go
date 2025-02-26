/*
 * @lc app=leetcode.cn id=922 lang=golang
 * @lcpr version=30204
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode.cn/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (71.59%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    145.5K
 * Total Submissions: 201.4K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
 *
 * 对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
 *
 * 你可以返回 任何满足上述条件的数组作为答案 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,3]
 * 输出：[2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 2 * 10^4
 * nums.length 是偶数
 * nums 中一半是偶数
 * 0 <= nums[i] <= 1000
 *
 *
 *
 *
 * 进阶：可以不使用额外空间解决问题吗？
 *
 */

// @lcpr-template-start
package main

import "fmt"

func main() {
	fmt.Println(sortArrayByParityII([]int{3, 2}))
}

// @lcpr-template-end
// @lc code=start
func sortArrayByParityII(nums []int) []int {
	for e, o, i := 0, 1, 0; i < len(nums); i++ {
		if nums[i]&1 == 1 && i&1 == 0 {
			// even exist a odd
			// find a even on odd place
			for o < len(nums) && nums[o]&1 == 1 {
				o += 2
			}
			nums[i], nums[o] = nums[o], nums[i]
		}
		if nums[i]&1 == 0 && i&1 == 1 {
			for e < len(nums) && nums[e]&1 == 0 {
				e += 2
			}
			nums[i], nums[e] = nums[e], nums[i]
		}
	}
	return nums
}

// @lc code=end

/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

*/
