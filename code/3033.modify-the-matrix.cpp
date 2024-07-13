/*
 * @lc app=leetcode.cn id=3033 lang=cpp
 * @lcpr version=30204
 *
 * [3033] 修改矩阵
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
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix)
    {
        int ma[60] = {0};
        int n = matrix.size(); // hang shu
        int m = matrix[0].size();
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                ma[j] = max(ma[j], matrix[i][j]);
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][j] = matrix[i][j] == -1 ? ma[j] : matrix[i][j];
            }
        }
        return matrix;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,-1],[4,-1,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,-1],[5,2]]\n
// @lcpr case=end

 */
