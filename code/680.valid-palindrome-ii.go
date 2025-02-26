/*
 * @lc app=leetcode.cn id=680 lang=golang
 * @lcpr version=30204
 *
 * [680] 验证回文串 II
 *
 * https://leetcode.cn/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (40.44%)
 * Likes:    691
 * Dislikes: 0
 * Total Accepted:    169.5K
 * Total Submissions: 410.4K
 * Testcase Example:  '"aba"'
 *
 * 给你一个字符串 s，最多 可以从中删除一个字符。
 *
 * 请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "aba"
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：s = "abca"
 * 输出：true
 * 解释：你可以删除字符 'c' 。
 *
 *
 * 示例 3：
 *
 * 输入：s = "abc"
 * 输出：false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 *
 *
 */

// @lcpr-template-start
package main

func main() {
	print(validPalindrome("aba"))
}

// @lcpr-template-end
// @lc code=start
func f(s string, able bool, l, r int) bool {
	if l >= r {
		return true
	} else if s[l] == s[r] {
		return f(s, able, l+1, r-1)
	} else {
		return able && (f(s, false, l+1, r) || f(s, false, l, r-1))
	}
}
func judge(s string, l, r int) bool {
	for l <= r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}
func validPalindrome(s string) bool {
	l, r := 0, len(s)-1
	for ; l < r && s[l] == s[r]; l, r = l+1, r-1 {
	}
	return s[l] == s[r] || judge(s, l+1, r) || judge(s, l, r-1)
}

// @lc code=end

/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

*/
