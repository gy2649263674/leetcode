/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        int dp[20] = {1};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i-1; j++)
            {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
    return dp[n];
    }
};
int main(void)
{
    Solution s;
    for(int i = 1;i<20;i++)
    {
        cout<<s.numTrees(i)<<'\t'<<(1<<i)<<endl;
    }
    return 0;
}
// @lc code=end
