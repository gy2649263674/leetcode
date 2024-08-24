/*
 * @lc app=leetcode.cn id=233 lang=cpp
 * @lcpr version=30204
 *
 * [233] 数字 1 的个数
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
    long long    countDigitOne(long long    n)
    {
        long long   dp[32] = {0ll, 1ll};
        for (long long    i = 2; i <= 31; i++)
        {
            dp[i] = dp[i-1]*2+ (1ull  << (i - 1));
        }
        long long    ans = 0;
        // function<void(long long   , long long   )> dfs = [&dfs, &dp, &ans](long long    left, long long    bit)
        // {
        //     if(bit<0)
        //     {
        //         return ;
        //     }
        //     if (left >= dp[bit])
        //     {
        //         ans += -1ll+(1ll << bit-1);
        //         dfs(left-dp[bit],bit-1);
        //     } 
        //     else{
        //         dfs(left,bit-1);
        //     }
        // };
        // dfs(n,30);
        for(int i = 0;n>>i;i++)
        {
            if(n>>i&1)
            {
                ans+= dp[i]+1;
            }
        }
        return ans;
    }
};


// @lc code=end

/*
// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */
int    main(void)
{
    Solution ss;
    ss.countDigitOne(13);
}