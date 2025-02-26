/*
 * @lc app=leetcode.cn id=464 lang=golang
 * @lcpr version=30204
 *
 * [464] 我能赢吗
 *
 * https://leetcode.cn/problems/can-i-win/description/
 *
 * algorithms
 * Medium (40.53%)
 * Likes:    561
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 110.1K
 * Testcase Example:  '10\n11'
 *
 * 在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和 达到或超过  100
 * 的玩家，即为胜者。
 *
 * 如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？
 *
 * 例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。
 *
 * 给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和 desiredTotal（累计和），若先出手的玩家能稳赢则返回
 * true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：maxChoosableInteger = 10, desiredTotal = 11
 * 输出：false
 * 解释：
 * 无论第一个玩家选择哪个整数，他都会失败。
 * 第一个玩家可以选择从 1 到 10 的整数。
 * 如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
 * 第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
 * 同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
 *
 *
 * 示例 2:
 *
 * 输入：maxChoosableInteger = 10, desiredTotal = 0
 * 输出：true
 *
 *
 * 示例 3:
 *
 * 输入：maxChoosableInteger = 10, desiredTotal = 1
 * 输出：true
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= maxChoosableInteger <= 20
 * 0 <= desiredTotal <= 300
 *
 *
 */

// @lcpr-template-start
package main

import "fmt"

func main() {
	fmt.Println(canIWin(18, 79))
	fmt.Println(canIWin(10, 11))
	fmt.Println(canIWin(10, 0))
	fmt.Println(canIWin(10, 1))
	fmt.Println(canIWin(10, 10))
}

// @lcpr-template-end
// @lc code=start
func canIWin(mx int, tar int) bool {
	// 第二维没必要，实际上由第一维度决定已获得的数值总和 
	var mp map[int]map[int]bool = map[int]map[int]bool{}
	if mx*(mx+1)/2 < tar {
		return false
	}
	if tar == 0 {
		return true
	}
	var dfs1 func(a int, b int) bool
	dfs1 = func(state, sum int) bool {
		if mp[state] == nil {
			mp[state] = map[int]bool{}
		}
		if v, ok := mp[state][sum]; ok {
			return v
		}
		// xian shou ying
		if sum >= tar {
			return false
		}
		if state == (1<<mx)-1 {
			return sum < tar
			// here is the sum of pre player
		} else {
			tmp := true
			for i := 0; i < mx; i++ {
				if 1<<i&state == 0 {
					// 必胜要求后面有一个必败
					// 必败要求后面全是必胜
					// all after should be lose
					tmp = tmp && dfs1(state|1<<i, sum+i+1)
					// no one is true
				}
			}
			mp[state][sum] = tmp == false // all after should be lose then return true means win
			return tmp == false
		}
	}
	return dfs1(0, 0)
}

// @lc code=end

/*
// @lcpr case=start
// 10\n11\n
// @lcpr case=end

// @lcpr case=start
// 10\n0\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n
// @lcpr case=end

*/
