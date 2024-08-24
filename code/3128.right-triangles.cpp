/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 * @lcpr version=30204
 *
 * [3128] 直角三角形
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
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> col(n, 0);
        // every col's 1
        vector<int> row(m, 0);
        // every row's 1
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ++col[j];
                    ++row[i];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans = ans + (col[j] - 1) * (row[i] - 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,0],[0,1,1],[0,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,1,0,1],[1,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1],[1,0,0],[1,0,0]]\n
// @lcpr case=end

 */
