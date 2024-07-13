/*
 * @lc app=leetcode.cn id=741 lang=cpp
 * @lcpr version=30203
 *
 * [741] 摘樱桃
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
#define pii pair<int, int>
class Solution
{
public:
    int dp[51][51][51];
    int solve(pii a, pii b, vector<vector<int>> &mp)
    {
        if (a.first >= mp.size() || a.second >= mp.size()
         || b.first >= mp.size() || mp[a.first][a.second] == -1 
         || mp[b.first][b.second] == -1)
        {
            return -1;
        }
        if (a.first == mp.size() - 1 && a.second == mp.size() - 1)
        {
            return mp.back().back();
        }

        if (dp[a.first][a.second][b.first] != -2)
        {
            return dp[a.first][a.second][b.first];
        }

        else
        {
            b = {b.first, a.first + a.second - b.first};
            int cur = a == b ? mp[a.first][a.second] : mp[a.first][a.second] + mp[b.first][b.second];
            int ans = 0;
            ans = max(solve({a.first, a.second + 1}, {b.first, b.second}, mp), ans);
            ans = max(solve({a.first, a.second + 1}, {b.first + 1, b.second}, mp), ans);
            ans = max(solve({a.first + 1, a.second}, {b.first, b.second}, mp), ans);
            ans = max(solve({a.first + 1, a.second}, {b.first + 1, b.second}, mp), ans);
            return dp[a.first][a.second][b.first] == ans == -1 ? -1 : ans + cur;
        }
    }
#include <string.h>
    int cherryPickup(vector<vector<int>> &grid)
    {
        // memset(&dp[0][0],-2,51*51*51);
        fill(&dp[0][0][0], &dp[0][0][0] + 51 * 51 * 51, -2);
        return solve({0, 0}, {0, 0}, grid);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,-1],[1,0,-1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,-1],[1,-1,1],[-1,1,1]]\n
// @lcpr case=end

 */
