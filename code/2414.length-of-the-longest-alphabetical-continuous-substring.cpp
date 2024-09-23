/*
 * @lc app=leetcode.cn id=2414 lang=cpp
 * @lcpr version=30204
 *
 * [2414] 最长的字母序连续子字符串的长度
 *
 * https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/description/
 *
 * algorithms
 * Medium (61.27%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 24.8K
 * Testcase Example:  '"abacaba"'
 *
 * 字母序连续字符串 是由字母表中连续字母组成的字符串。换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意子字符串都是
 * 字母序连续字符串 。
 * 
 * 
 * 例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。
 * 
 * 
 * 给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abacaba"
 * 输出：2
 * 解释：共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
 * "ab" 是最长的字母序连续子字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abcde"
 * 输出：5
 * 解释："abcde" 是最长的字母序连续子字符串。
 * 
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
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int res = 1;
        for(int i  = 0;i+1<s.length();i++)
        {
            ans =s[i+1]-s[i] == 1?ans+1:1;
            res = max(res,ans);
        }
        return res;
    }

};
// @lc code=end



/*
// @lcpr case=start
// "abacaba"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n
// @lcpr case=end

 */

