/*
 * @lc app=leetcode.cn id=38 lang=cpp
 * @lcpr version=30204
 *
 * [38] 外观数列
 *
 * https://leetcode.cn/problems/count-and-say/description/
 *
 * algorithms
 * Medium (61.04%)
 * Likes:    1093
 * Dislikes: 0
 * Total Accepted:    377.5K
 * Total Submissions: 617.9K
 * Testcase Example:  '1'
 *
 * 「外观数列」是一个数位字符串序列，由递归公式定义：
 *
 *
 * countAndSay(1) = "1"
 * countAndSay(n) 是 countAndSay(n-1) 的行程长度编码。
 *
 *
 *
 *
 *
 *
 *
 *
 * 行程长度编码（RLE）是一种字符串压缩方法，其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的串联。例如，要压缩字符串
 * "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11"
 * 替换。因此压缩后字符串变为 "23321511"。
 *
 * 给定一个整数 n ，返回 外观数列 的第 n 个元素。
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 *
 * 输出："1211"
 *
 * 解释：
 *
 * countAndSay(1) = "1"
 *
 * countAndSay(2) = "1" 的行程长度编码 = "11"
 *
 * countAndSay(3) = "11" 的行程长度编码 = "21"
 *
 * countAndSay(4) = "21" 的行程长度编码 = "1211"
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 *
 * 输出："1"
 *
 * 解释：
 *
 * 这是基本情况。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 30
 *
 *
 *
 * 进阶：你能迭代解决该问题吗？
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
    string ans;
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return ans = "1";
        }
        else
        {
            string tmp;
            for (int i = 0; i < ans.length();)
            {
                int cnt = 0;
                while (i < ans.length() && ans[i] == ans[i + 1])
                {
                    ++cnt;
                    ++i;
                }
                tmp += to_string(cnt) + ans[i];
            }
            return ans = tmp;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
