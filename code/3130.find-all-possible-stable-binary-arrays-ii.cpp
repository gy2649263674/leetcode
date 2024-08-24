/*
 * @lc app=leetcode.cn id=3130 lang=cpp
 * @lcpr version=30204
 *
 * [3130] 找出所有稳定的二进制数组 II
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
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int dp[1000][1000] = {0};
        for (int i = 0; i < zero; i++)
        {
            for (int j = 0; j < one; j++)
            {
                // you yi ge yi
                for (int l = 0; l < limit; l++)
                {
                    dp[i][j] = dp[][j - 1]
                }
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n2\n
// @lcpr case=end

 */
