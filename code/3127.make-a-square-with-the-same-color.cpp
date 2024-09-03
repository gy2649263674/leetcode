/*
 * @lc app=leetcode.cn id=3127 lang=cpp
 * @lcpr version=30204
 *
 * [3127] 构造相同颜色的正方形
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
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        function<bool(void)> check = [&](void) -> bool
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i + 1][j + 1])
                    {
                        return true;
                    }
                }
            }
            return false;
        };
        if (check())
        {
            return true;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = grid[i][j] == 'W' ? 'B' : 'W';
                if (check())
                {
                    return true;
                }
                grid[i][j] = grid[i][j] == 'W' ? 'B' : 'W';
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["B","W","B"],["B","W","W"],["B","W","B"]]\n
// @lcpr case=end

// @lcpr case=start
// [["B","W","B"],["W","B","W"],["B","W","B"]]\n
// @lcpr case=end

// @lcpr case=start
// [["B","W","B"],["B","W","W"],["B","W","W"]]\n
// @lcpr case=end

 */
