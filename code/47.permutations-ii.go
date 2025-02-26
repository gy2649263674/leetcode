/*
 * @lc app=leetcode.cn id=47 lang=golang
 * @lcpr version=30204
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (66.15%)
 * Likes:    1648
 * Dislikes: 0
 * Total Accepted:    618.6K
 * Total Submissions: 933.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lcpr-template-start
package main

import "fmt"

func main() {
	fmt.Println(permuteUnique([]int{1, 1, 2}))
}

// @lcpr-template-end
// @lc code=start
var res [][]int

func solve1(arr []int, ind int) {
	if ind == len(arr) {
		res = append(res, append([]int{}, arr...))
		return
	} else {
		var vis map[int]bool = map[int]bool{}
		for i := ind; i < len(arr); i++ {
			if vis[arr[i]] == false {
				vis[arr[i]] = true
				arr[ind], arr[i] = arr[i], arr[ind]
				solve1(arr, ind+1)
				arr[ind], arr[i] = arr[i], arr[ind]
			}
		}
		return
	}

}

func permuteUnique(nums []int) [][]int {
	res = [][]int{}
	solve1(nums, 0)
	return res
}

// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

*/
