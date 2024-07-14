/*
 * @lc app=leetcode.cn id=807 lang=cpp
 * @lcpr version=30204
 *
 * [807] 保持城市天际线
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
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> row(n, 0), col(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                col[j] = max(col[j], grid[i][j]);
                row[i] = max(row[i], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += max(min(row[i], col[j]) - grid[i][j], 0);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0],[0,0,0]]\n
// @lcpr case=end

 */
