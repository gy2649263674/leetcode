/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.45%)
 * Likes:    1509
 * Dislikes: 0
 * Total Accepted:    509.1K
 * Total Submissions: 952.2K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 *
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
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
#include <bits/stdc++.h>
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string &s, string &p)
    {
        if (s.length() < p.length())
        {
            return {};
        }
        vector<int> mp(26, 0);
        vector<int> mt(26, 0);
        for (int i = 0; i < p.length(); i++)
        {
            ++mp[p[i] - 'a'];
        }
        int n = p.length();
        for (int i = 0; i < n; i++)
        {
            ++mt[s[i] - 'a'];
        }
        vector<int> ans;
        for (int j = 0; j + n <= s.length(); j++)
        {
            if (mt == mp)
            {
                ans.push_back(j);
            }
            --mt[s[j]-'a'];
            if (j + n != s.length())
                ++mt[s[j + n]-'a'];
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
    return 0;
}
/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
