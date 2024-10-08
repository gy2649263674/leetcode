/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (41.64%)
 * Likes:    1295
 * Dislikes: 0
 * Total Accepted:    537.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m -
 * 1][n - 1]）。机器人每次只能向下或者向右移动一步。
 *
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
 *
 * 返回机器人能够到达右下角的不同路径数量。
 *
 * 测试用例保证答案小于等于 2 * 10^9。
 *
 *
 *
 * 示例 1：
 *
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 *
 *
 * 示例 2：
 *
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 *
 *
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
    int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid)
    {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        long long dp[110][110] = {0};
        dp[m - 1][n - 1] = obstacleGrid[m-1][n-1] == 0 ? 1 : 0;
        // for (int i = m - 1; i >= 0; i--)
        // {
        //     dp[i][n - 1] = 1;
        // }
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     dp[m - 1][i] = 1;
        // }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                // dp[i][j+1],
                // dp[i+1][j]
                if(j+1<=n-1 && obstacleGrid[i][j+1] == 0)
                {
                    dp[i][j]+=dp[i][j+1];
                }
                if(i+1<=m-1 && obstacleGrid[i+1][j] == 0)
                {
                    dp[i][j]+=dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout<<s.uniquePathsWithObstacles({{0,0}})<<endl;
    return 0;
}
/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */