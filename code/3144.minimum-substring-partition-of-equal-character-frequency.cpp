/*
 * @lc app=leetcode.cn id=3144 lang=cpp
 * @lcpr version=30204
 *
 * [3144] 分割字符频率相等的最少子字符串
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
// #include <bits/stdc++.h>
//  @lcpr-template-end
//  @lc code=start
class Solution
{
public:
    int minimumSubstringsInPartition(string s)
    {

        int dp[1001] = {0};
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            unordered_map<char, int> tot;
            int maxn = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                maxn = max(maxn, ++tot[s[j]]);
                if (tot.size() * maxn == (i - j))
                    dp[i] = min(dp[j] + 1, dp[i]);
            }
        }
        return dp[s.length()];
        // ss = s;
        int pre[1001][26];
        // memset(pre[0], 0, sizeof(pre));
        // self and don't include pre
        // for (int i = 1; i <= s.length(); i++)
        // {
        //     for (int j = 0; j < 26; j++)
        //     {
        //         pre[i][j] = pre[i - 1][j] + (s[i - 1] == 'a' + j ? 1 : 0);
        //         // the i st char0
        //     }
        // }

        function<bool(int, int)> check = [&](int p, int s) -> bool
        {
            if (s - p == 1)
            {
                return true;
            }
            vector<int> tmp;
            for (int i = 0; i < 26; i++)
            {
                int c = pre[s][i] - pre[p][i];
                // ignore p self
                if (!tmp.empty() && c != tmp.back() && c != 0)
                {
                    return false;
                }
                if (c)
                {
                    tmp.push_back(c);
                }
            }
            return true;
        };
        function<int(int)> f = [&](int cur) -> int
        {
            if (cur == 0)
            {
                return 0;
            }
            if (cur == 1)
            {
                return 1;
            }
            if (dp[cur] != 0)
            {
                return dp[cur];
            }
            int ans = 1e9;
            int maxele = 0;
            unordered_map<char, int> maxn;
            for (int i = cur - 1; i >= 0; i--)
            {
                maxele = max(++maxn[s[i]], maxele);
                if (maxele * maxn.size() == (cur - i))
                {
                    ans = min(f(i) + 1, ans);
                }
                // i is used
                // if (check(i, cur))
                // {
                //     ans = min(f(i) + 1, ans);
                // }
            }
            return dp[cur] = ans;
        };
        return f(s.length());
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.minimumSubstringsInPartition("dasdasdf");
    return 0;
}
/*
// @lcpr case=start
// "fabccddg"\n
// @lcpr case=end

// @lcpr case=start
// "abababaccddb"\n
// @lcpr case=end

 */
