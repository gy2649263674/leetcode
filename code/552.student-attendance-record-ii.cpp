/*
 * @lc app=leetcode.cn id=552 lang=cpp
 * @lcpr version=30204
 *
 * [552] 学生出勤记录 II
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
    long long dp[100002][3][4] = {0};
    const int mod = 1e9 + 7;
    long long solve(int A, int L, int n)
    {
        if (n == 0 && A != 0 && L != 0)
        {
            return 1;
        }
        if (A == 0 || L == 0)
        {
            return 0;
        }
        if (dp[n][A][L] != 0)
        {
            return dp[n][A][L];
        }
        else
        {
            return dp[n][A][L] = ((solve(A - 1, 3, n - 1) + solve(A, L - 1, n - 1) + solve(A, 3, n - 1))) % mod;
        }
    }
    int checkRecord(int n)
    {
        return solve(2, 3, n);
    }
};
class Solution
{
public:
    int checkRecord(int n)
    {
        int dp[2][3] = {1};
        // meet requests
        for (int i = 0; i < n; i++)
        {
            // end with p
            for (int j = 1; j > 0; j++)
            {
                for (int l = 2; l > 0; l++)
                {
                    dp[j][l] = dp[j][0]
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            // end with A
            for (int j = 1; j > 0; j--)
                for (int l = 0; l < 3; l++)
                {
                    dp[j][l] = dp[j - 1][l];
                }
        }
        for (int i = 0; i < n; i++)
        {
            // end with A
            for (int j = 1; j > 0; j--)
                for (int l = 0; l < 3; l++)
                {
                    dp[j][l] = dp[j - 1][l];
                }
        }
        return 0;
    }

    // class matrix
    // {
    //     int m, n;
    //     vector<vector<int>> arr;
    //     matrix(int m, int n)
    //     {
    //         arr = vector<vector<int>>(m, vector<int>(n));
    //     }
    //     void operator=(int *a)
    //     {}

    // };
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 10101\n
// @lcpr case=end

 */
