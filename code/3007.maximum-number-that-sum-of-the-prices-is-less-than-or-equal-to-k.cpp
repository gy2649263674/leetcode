/*
 * @lc app=leetcode.cn id=3007 lang=cpp
 * @lcpr version=30204
 *
 * [3007] 价值和小于等于 K 的最大数字
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
   long long    violent(long long k,long long    x)
    {
        long long tmp = 0;
        long long i = 0;
        for (; tmp <= k; i++)
        {
            for (long long j = x - 1; (i >> j) != 0; j += x)
            {
                if ((i >> j) & 1ll)
                {
                    tmp += 1ll;
                }
                // cout << tt << endl;
            }
        }
        return i - 2;
    }
    long long findMaximumNumber(long long k,long long    x)
    {

        long long dp[64] = {x == 1?1:0};
        for (long long    i = 1; i < 63; i++)
        {
            // high bit is i
            dp[i] = dp[i - 1] + ((i % x == 0) ? (1ll << i) : 0);
        }
        // all sum pre
        // if k>1<<i must choose i
        // sum behind max is 1<<i -1
        // 1 2 2  3 3 3 3
        long long ans = 0;
        function<void(long long   ,long long   )> find =
            [&find, &dp, &ans](long long    cur,long long    i)
        {
            if (i < 0 )
            {
                return;
            }
            if ((cur - (dp[i])) >= 0)
            {
                ans |= 1ll << i;
                return find(cur - dp[i], i - 1);
            }
            else
            {
                return find(cur, i - 1);
            }
            // return find((cur - (1 << i)) >= 0 ? (cur - (1 << i)) : cur, i - 1);
        };
        find(k, 55);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 9\n1\n
// @lcpr case=end

// @lcpr case=start
// 7\n2\n
// @lcpr case=end

 */
int   main(void)
{
    Solution s;
    cout << s.findMaximumNumber(7, 2);
    return 0;
}