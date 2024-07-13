/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int *dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0, _2 = 0, _3 = 0, _5 = 0; i < n; i++)
        {
            int n1 = dp[_2] * 2, n2 = dp[_3] * 3, n3 = dp[_5] * 5;
            int val = min({n1,n2,n3});
            if(val == n1)
            {
                ++_2;
            }
            if(val == n2)
            {
                ++_3;
            }
            if(val == n3)
            {
                ++_5;
            }
            dp[i+1] = val;
        }
        return dp[n-1];
    }

};
// @lc code=end
