/*
 * @lc app=leetcode.cn id=219 lang=golang
 * @lcpr version=30204
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode.cn/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (48.29%)
 * Likes:    767
 * Dislikes: 0
 * Total Accepted:    366.5K
 * Total Submissions: 749.8K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且
 * abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：true
 *
 * 示例 2：
 *
 * 输入：nums = [1,0,1,1], k = 1
 * 输出：true
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3,1,2,3], k = 2
 * 输出：false
 *
 *2
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 *
 *
 */

// @lcpr-template-start
package main

func main() {
	print(containsNearbyDuplicate([]int{5, 4, 6, 2, 0, 2}, 2))
	containsNearbyDuplicate([]int{1, 0, 1, 1}, 1)
	containsNearbyDuplicate([]int{1, 2, 3, 1, 2, 3}, 2)
}

// @lcpr-template-end
// @lc code=start
func containsNearbyDuplicate(nums []int, k int) bool {
	mp := make(map[int]int, k)
	i := 0
	for ; i < min(len(nums), k); i++ {
		mp[nums[i]]++
		if mp[nums[i]] > 1 {
			return true
		}
	}
	l := 0
	for i < len(nums) {
		mp[nums[i]]++
		if mp[nums[i]] > 1 {
			return true
		}
		mp[nums[l]]--
		if mp[nums[l]] == 0 {
			delete(mp, nums[l])
		}
		i++
		l++
	}
	return false
}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

*/
