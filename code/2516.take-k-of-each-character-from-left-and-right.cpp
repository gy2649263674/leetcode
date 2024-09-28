/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 * @lcpr version=30204
 *
 * [2516] 每种字符至少取 K 个
 *
 * https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/description/
 *
 * algorithms
 * Medium (41.49%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    17.1K
 * Total Submissions: 36.7K
 * Testcase Example:  '"aabaaaacaabc"\n2'
 *
 * 给你一个由字符 'a'、'b'、'c' 组成的字符串 s 和一个非负整数 k 。每分钟，你可以选择取走 s 最左侧 还是 最右侧 的那个字符。
 *
 * 你必须取走每种字符 至少 k 个，返回需要的 最少 分钟数；如果无法取到，则返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "aabaaaacaabc", k = 2
 * 输出：8
 * 解释：
 * 从 s 的左侧取三个字符，现在共取到两个字符 'a' 、一个字符 'b' 。
 * 从 s 的右侧取五个字符，现在共取到四个字符 'a' 、两个字符 'b' 和两个字符 'c' 。
 * 共需要 3 + 5 = 8 分钟。
 * 可以证明需要的最少分钟数是 8 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "a", k = 1
 * 输出：-1
 * 解释：无法取到一个字符 'b' 或者 'c'，所以返回 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 仅由字母 'a'、'b'、'c' 组成
 * 0 <= k <= s.length
 *
 *
 */

 // @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
	int takeCharacters(string s, int k)
	{
		int n = s.length();
		vector<int> st(3, 0);
		for (int i = 0; i < s.length(); i++)
		{
			++st[s[i] - 'a'];
		}
		if (k == 0)
		{
			return 0;
		}
		if (*min_element(st.begin(), st.end()) < k)
		{
			return -1;
		}
		int l = 0, r = 0;
		vector<int> cur(3, 0);
		int ans = 1000000;
		++cur[s[0] - 'a'];
		while (l < n && r < n)
		{
			if (st[0] - cur[0] < k || st[1] - cur[1] < k || st[2] - cur[2] < k)
			{
				--cur[s[l] - 'a'];
				++l;
			}
			// ++r will extend the window and decrease the useful val 
			else
			{

				//(0,l) (r

				ans = min(ans, n + 1 - (r - l));
				++cur[s[r] - 'a'];
				++r;
				// the min in l r to the max want
			}
		}
		return ans > n ? -1 : ans;
	}
};
//// @lc code=end
//int main(void)
//{
//	Solution s;
//	cout << s.takeCharacters("acbcc", 1);
//	return 0;
//}
/*
// @lcpr case=start
// "aabaaaacaabc"\n2\n
// @lcpr case=end

// @lcpr case=start
// "a"\n0\n
// @lcpr case=end

 */
