/*
 * @lc app=leetcode.cn id=68 lang=golang
 * @lcpr version=30204
 *
 * [68] 文本左右对齐
 *
 * https://leetcode.cn/problems/text-justification/description/
 *
 * algorithms
 * Hard (55.56%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    97.7K
 * Total Submissions: 175.5K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 *
 * 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth
 * 个字符。
 *
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 *
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 *
 * 注意:
 *
 *
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: words = ["This", "is", "an", "example", "of", "text", "justification."],
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 *
 * 示例 2:
 *
 * 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 *
 *
 * 示例 3:
 *
 * 输入:words =
 * ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth
 * = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] 由小写英文字母和符号组成
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 *
 *
 */

// @lcpr-template-start
package main

import (
	"fmt"
	"strings"
)

func main() {
	// fmt.Println(len(strings.Join([]string{"1", "2"}, " ")))
	fmt.Println(fullJustify([]string{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we"},
		20))
}

// @lcpr-template-end
// @lc code=start
// 尽可能均匀分配单词间的
func fullJustify(words []string, maxWidth int) []string {
	res := [][]string{}
	for i := 0; i < len(words); {
		var cnt int = 0
		sum := 0
		j := i
		// for中的条件实质上是判断加入新单词后是否超过maxWidth，cnt应该使用下一次的cnt
		for ; j < len(words) && sum+cnt+len(words[j]) <= maxWidth; j++ {
			sum += len(words[j])
			cnt++
		}
		res = append(res, words[i:j])
		i = j
	}
	ans := []string{}
	getSum := func(s []string) int {
		sum := 0
		for _, v := range s {
			sum += len(v)
		}
		return sum
	}
	for j, vecs := range res {
		sp := maxWidth - getSum(vecs)
		num := len(vecs) - 1
		if j == len(res)-1 {
			break
		}
		var ss string = ""
		for i, s := range vecs {
			if len(vecs) == 1 {
				ss += s + strings.Repeat(" ", sp)
				break
			}
			ss += s
			if i != len(vecs)-1 {
				spn := (sp + num - 1) / num
				num--
				sp -= spn
				ss += strings.Repeat(" ", spn)
			}
		}
		ans = append(ans, ss)
	}
	ss := strings.Join(res[len(res)-1], " ")
	ss += strings.Repeat(" ", maxWidth-len(ss))
	fmt.Println((ss))
	ans = append(ans, ss)
	fmt.Println(ans)
	return ans
}

// @lc code=end

/*
// @lcpr case=start
// ["This", "is", "an", "example", "of", "text", "justification."]\n16\n
// @lcpr case=end

// @lcpr case=start
// ["What","must","be","acknowledgment","shall","be"]\n16\n
// @lcpr case=end

// @lcpr case=start
// ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we"]\n20\n
// @lcpr case=end
*/
