/*
 * @lc app=leetcode.cn id=329 lang=cpp
 * @lcpr version=30204
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (52.54%)
 * Likes:    870
 * Dislikes: 0
 * Total Accepted:    115.6K
 * Total Submissions: 219.9K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
 *
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * 输出：4
 * 解释：最长递增路径为 [1, 2, 6, 9]。
 *
 * 示例 2：
 *
 * 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * 输出：4
 * 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 *
 *
 * 示例 3：
 *
 * 输入：matrix = [[1]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
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
    int longestIncreasingPath1(vector<vector<int>> &mp)
    {
        int x_[4] = {0, 0, 1, -1};
        int y_[4] = {1, -1, 0, 0};
        int m = mp.size(), n = mp[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        function<int(int, int)> dfs = [&](int x, int y) -> int
        {
            if (dp[x][y])
            {
                return dp[x][y];
            }
            if (x >= m || x < 0 || y >= n || y < 0)
            {
                return 0;
            }
            else
            {
                int ans = 0;
                for (int i = 0; i < 4; i++)
                {
                    int x1 = x + x_[i], y1 = y + y_[i];
                    if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && mp[x1][y1] > mp[x][y])
                    {
                        ans = max(ans, 1 + dfs(x1, y1));
                    }
                }
                return dp[x][y] = ans;
            }
        };
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(dfs(i, j), ans);
            }
        }
        return ans + 1;
    }
    int longestIncreasingPath(vector<vector<int>> &mp)
    {
        int x_[4] = {0, 0, 1, -1};
        int y_[4] = {1, -1, 0, 0};
        int m = mp.size(), n = mp[0].size();
        vector<vector<int>> out(m, vector<int>(n, 0));
        queue<pair<int, int>> aux;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + x_[k], y = j + y_[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && mp[x][y] > mp[i][j])
                    {
                        out[i][j]++;
                    }
                }
                if (out[i][j] == 0)
                {
                    aux.push({i, j});
                }
            }
            // can reach to others
        }
        int ans = 0;
        while (aux.empty() == false)
        {
            ++ans;
            int sz = aux.size();
            while (sz--)
            {
                auto [x, y] = aux.front();
                aux.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x1 = x + x_[i], y1 = y + y_[i];
                    if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && mp[x1][y1] < mp[x][y])
                    {
                        --out[x1][y1];
                        if (out[x1][y1] == 0)
                            aux.push({x1, y1});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[9,9,4],[6,6,8],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,5],[3,2,6],[2,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */
