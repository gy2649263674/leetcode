/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include <bits\stdc++.h>
// @lc code=start
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int dp[200][200];
        dp[0][0] = triangle[0][0];
        int i = 0;
        for (; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j >= 1)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                else
                {
                    dp[i][0] = dp[i - 1][0];
                }
            }
        }
        return *min_element(dp[i-1], dp[i-1] + triangle[triangle.size() - 1].size());
    }
};
// int main(void)
// {
//     Solution s;
//     s.minimumTotal(vector<vector<int> >());
//     return 0;
// }
// @lc code=end
