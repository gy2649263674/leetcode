/*
 * @lc app=leetcode.cn id=466 lang=cpp
 * @lcpr version=30204
 *
 * [466] 统计重复个数
 *
 * https://leetcode.cn/problems/count-the-repetitions/description/
 *
 * algorithms
 * Hard (41.61%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 61.4K
 * Testcase Example:  '"acb"\n4\n"ab"\n2'
 *
 * 定义 str = [s, n] 表示 str 由 n 个字符串 s 连接构成。
 *
 *
 * 例如，str == ["abc", 3] =="abcabcabc" 。
 *
 *
 * 如果可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。
 *
 *
 * 例如，根据定义，s1 = "abc" 可以从 s2 = "abdbec" 获得，仅需要删除加粗且用斜体标识的字符。
 *
 *
 * 现在给你两个字符串 s1 和 s2 和两个整数 n1 和 n2 。由此构造得到两个字符串，其中 str1 = [s1, n1]、str2 = [s2,
 * n2] 。
 *
 * 请你找出一个最大整数 m ，以满足 str = [str2, m] 可以从 str1 获得。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 * 输入：s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s1.length, s2.length <= 100
 * s1 和 s2 由小写英文字母组成
 * 1 <= n1, n2 <= 10^6
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
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        // s2*n2;
        // s1*n1;
        //  to find a num that fit same quences num need int s1 and int s2;
        int dp[1000][1000];
        int l1 = s1.length(), l2 = s2.length();
        pair<int,int>ans = {};
        for (int i = 1; i <= l1 * n1; i++)
        {
            for (int j = 1; j <= l2 * n2; j++)
            {
                if (s1[(i - 1) % l1] == s2[(j - 1) % l2])
                {
                    dp[i][j] == dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] % l2 && i % l2)
                {
                    ans = {i,j};
                    break;
                }
            }
        }
        // 
        int u1 = ans.first%l1,u2 = ans.second%l2;
        return +
    }
};
// @lc code=end

/*
// @lcpr case=start
// "acb"\n4\n"ab"\n2\n
// @lcpr case=end

// @lcpr case=start
// "acb"\n1\n"acb"\n1\n
// @lcpr case=end

 */
