/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (43.73%)
 * Likes:    2274
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.6M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 *
 *
 * 示例 2：
 *
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
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
    int next[10001] = {0};
    void build(string &s)
    {
        for (int i = 0, l = 1; l < s.length(); l++)
        {
            if (s[i] == s[l])
            {
                next[l] = ++i;
            }
            else
            {
                while (i != 0 && s[i] != s[l] && s[i] != i)
                {
                    i = next[i-1];
                    //向前跳时根据next数组的含义，总是可以知道此时l前长度为i的部分与[0,i)有公共部分
                }
                next[l] = s[i] == s[l] ? ++i : 0;
            }
        }
        return;
    }
    int strStr(string big, string needle)
    {
        build(needle);
        int sm = 0;
        for (int i = 0; i < big.length(); i++)
        {
            if (sm == needle.length())
            {
                return i - needle.length();
            }
            if (big[i] == needle[sm])
            {
                ++sm;
            }
            else
            {
                // i--;
                while (needle[sm] != big[i] && sm != 0 && sm != next[sm])
                    sm = next[sm-1];
                sm = needle[sm] == big[i] ? ++sm : 0;
            }
        }
        return sm == needle.length() ? big.length() - needle.length() : -1;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    s.strStr(string("aaaaa"), string("bba"));
    return 0;
}

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

// @lcpr case=start
// "aaaaa"\n"bba"\n
// @lcpr case=end

 */
