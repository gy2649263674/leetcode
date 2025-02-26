/*
 * @lc app=leetcode.cn id=40 lang=golang
 * @lcpr version=30204
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.71%)
 * Likes:    1645
 * Dislikes: 0
 * Total Accepted:    594.9K
 * Total Submissions: 993.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。
 *
 *
 *
 * 示例 1:
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50/
 * 1 <= target <= 30
 *
 *
 */

// @lcpr-template-start
package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println((combinationSum2([]int{10, 1, 2, 7, 6, 1, 5}, 8)))
	fmt.Println((combinationSum2([]int{2, 5, 2, 1, 2}, 5)))
}

// @lcpr-template-end
// @lc code=start
var vis []bool
var res [][]int
var tar int
var arr []int

func dfs(ind, sum int, vec []int) {
	if sum == tar {
		res = append(res, append([]int{}, vec...))
		return
	} else if ind == len(arr) {
		return
	} else if sum+arr[ind] <= tar {
		dfs(ind+1, sum, vec)
		if (arr[ind] == arr[ind-1] && vis[ind-1] == true) || arr[ind] != arr[ind-1] {
			vis[ind] = true
			dfs(ind+1, sum+arr[ind], append(vec, arr[ind]))
			vis[ind] = false
		}
	}
}
func combinationSum2(nums []int, t int) [][]int {
	res = [][]int{}
	tar = t
	sort.Ints(nums)
	arr = append([]int{}, nums...)
	vis = make([]bool, len(arr))
	vis[0] = true
	dfs(1, nums[0], []int{arr[0]})
	vis[0] = false
	dfs(1, 0, []int{})
	return res
}

// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end` `
w
*/
