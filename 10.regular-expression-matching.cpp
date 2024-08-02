/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=30204
 *
 * [10] 正则表达式匹配
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
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int dp[30][30];
    string s, p;
    bool isMatch(string s, string p)
    {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        this->p = p;
        return dfs(s.length() - 1, p.length() - 1);
    }
    int dfs(int ss, int pp)
    {
        if (ss < 0 || pp < 0)
        {
            return false;
        }
        if (dp[ss][pp] != -1)
        {
            return dp[ss][pp];
        }
        if (p[pp] == '*')
        {
            return dp[ss][pp] = dfs(ss - 1, pp - 1) | dfs(ss, pp - 1);
        }
        else if (p[pp] == '.')
        {
            return dp[ss][pp] = dfs(ss - 1, pp - 1);
        }
        else
        {
            return dp[ss][pp] = s[ss] == p[pp];
        }
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    return 0;
}
/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */
