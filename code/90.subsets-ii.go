/*
 * @lc app=leetcode.cn id=90 lang=golang
 * @lcpr version=30204
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.60%)
 * Likes:    1266
 * Dislikes: 0
 * Total Accepted:    417.7K
 * Total Submissions: 655.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
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
	fmt.Println(subsetsWithDup([]int{1, 1, 2, 2, 3}))
}

// @lcpr-template-end
// @lc code=start

func extend(t, res *[][]int, ind int, cur []int) {
	// only exist 1 in cur
	if ind == len(*t) {
		tmp := make([]int, len(cur))
		copy(tmp, cur)
		*res = append(*res, tmp)
		return
	}
	for i := 0; i <= (*t)[ind][1]; i++ {
		if i != 0 {
			cur = append(cur, (*t)[ind][0])
		}
		extend(t, res, ind+1, cur)
	}
	cur = cur[:len(cur)-(*t)[ind][1]]
}
func subsetsWithDup(nums []int) [][]int {
	// t := make([]int, len(nums)+offset)
	sort.Ints(nums)
	res, t := [][]int{}, [][]int{}
	for _, v := range nums {
		if len(t) == 0 || v != t[len(t)-1][0] {
			t = append(t, []int{v, 1})
		} else {
			t[len(t)-1][1]++
		}
	}
	extend(&t, &res, 0, []int{})
	return res
}

//// @lc code=end

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

*/
// func subsetsWithDup1(nums []int) [][]int {
// 	times := map[int]int{}
// 	for _, v := range nums {
// 		times[v]++
// 	}
// 	filter(&nums)
// 	res := [][]int{}
// 	for i := 0; i < 1<<len(nums); i++ {
// 		tmp := []int{}
// 		for j := 0; j < len(nums); j++ {
// 			if (i>>j)&1 == 1 {
// 				tmp = append(tmp, nums[j])
// 			}
// 		}
// 		res = append(res, tmp)
// 	}
// 	t := len(res)
// 	for i, vec := 0, res[0]; i < max(t, len(res)); i++ {
// 		vec = res[i]
// 		tmp := map[int]int{}
// 		for _, v := range vec {
// 			tmp[v]++
// 		}
// 		for _, v := range vec {
// 			if times[v] > tmp[v] {
// 				res = append(res, append(vec, v))
// 				tmp[v]++
// 			}
// 		}
// 		t = len(res)
// 	}
// 	return res
// }
