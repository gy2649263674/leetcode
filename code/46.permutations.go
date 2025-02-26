/*
 * @lc app=leetcode.cn id=46 lang=golang
 * @lcpr version=30204
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (79.94%)
 * Likes:    3019
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 *
 *
 */

// @lcpr-template-start
package main

import "fmt"

func main() {
	fmt.Print(permute([]int{1, 2, 3}))
}

// @lcpr-template-end
// @lc code=start
var res [][]int

func solve(arr []int, ind int) {
	if ind == len(arr) {
		res = append(res, append([]int{}, arr...))
		return
	} else {
		for i := ind; i < len(arr); i++ {
			arr[ind], arr[i] = arr[i], arr[ind]
			solve(arr, ind+1)
			arr[ind], arr[i] = arr[i], arr[ind]
		}
		return
	}

}
func permute(nums []int) [][]int {
	res = [][]int{}
	solve(nums, 0)
	return res
}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

*/
