/*
 * @lc app=leetcode.cn id=2844 lang=cpp
 * @lcpr version=30204
 *
 * [2844] 生成特殊数字的最少操作
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
    int minimumOperationsdp(string &num)
    {
        int dp[101][30];
        // 到第i个数字，使得后面能够被25整除，最少，反向加数
        function<int(int, int)> dfs = [&](int i, int j)
        {
            if (i == num.size())
            {
                return dp[i][j] = j == 0 ? 0 : 1e9;
            }
            if (dp[i][j] != -1)
                return dp[i][j];
            else
            {
                dp[i][j] = min(dfs(i + 1, (j * 10 + num[i] - '0') % 25), 1 + dfs(i + 1, j));
            }
            return dp[i][j];
        };
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0);
    }
    int minimumOperations(string &num)
    {
        int n = num.length();
        int h0 = -1, h5 = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (num[i] == '0')
            {
                if (h0 != -1)
                {
                    return n - i - 2;
                }
                h0 = i;
            }
            else if (num[i] == '5')
            {
                if (h0 != -1)
                {
                    return n - i - 2;
                }
                h5 = i;
            }
            else if (num[i] == '2' || num[i] == '7')
            {
                if (h5 != -1)
                {
                    return n - i - 2;
                }
            }
        }
        return h0!= -1?n-1:n;
    }
};

/*
记忆化搜索 做个无脑思路的补充，把删除某些数位转化为保留某些数位。
 状态定义 f[i][sum]表示当前遍历到数位i（i=0是最高位），且数位[0,i)组成的数字模上25的结果是sum的情况下，
 把后面的数字填好得到特殊数字的最少操作次数。在这个定义下，答案就应该是f[0][0]。 状态转移 base case：如果i=n时满足sum=0，
 说明凑出来了一个能被25整除的数，返回0。 一般情况：否则当前数位可以删除也可以保留，有两种情况，
 选操作数较小的转移来源转移。状态转移方程为f[i][sum]=min(f[i+1][(10×sum+num[i])%25],1+f[i+1][sum])。*/
// @lc code=end

/*
// @lcpr case=start
// "2245047"\n
// @lcpr case=end

// @lcpr case=start
// "2908305"\n
// @lcpr case=end

// @lcpr case=start
// "10"\n
// @lcpr case=end

 */
