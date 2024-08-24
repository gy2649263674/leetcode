/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30204
 *
 * [37] 解数独
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
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    grid[get_ri(i,j)]
                }   
            }
        }
    }
    unordered_set<char> col[9], row[9], grid[9];
    int get_ri(int x, int y)
    { // 0 1 2
        // 3 4 5
        // 6 7 8
        if (x <= 2 && y <= 2)
        {
            return 0;
        }
        else if (x <= 2 && y <= 5)
        {
            return 1;
        }
        else if (x <= 2 && y <= 8)
        {
            return 2;
        }
        else if (x <= 5 && y <= 2)
        {
            return 3;
        }
        else if (x <= 5 && y <= 5)
        {
            return 4;
        }
        else if (x <= 5 && y <= 8)
        {
            return 5;
        }
        else if (y <= 2)
        {
            return 6;
        }
        else if (y <= 5)
        {
            return 7;
        }
        else if (y <= 8)
        {
            return 8;
        }
    }
    bool dfs(int x, int y, vector<vector<int>> &board)
    {
        if (x == 9)
        {
            return true;
        }
        if (y == 9)
        {
            return dfs(x + 1, 0, board);
        }
        bool ok = false;
        if (board[x][y] != '.')
        {
            for (char c : row[x])
            {
                int rig = get_ri(x, y);
                if (col[y].count(c) == 0 && grid[rig].count(c) == 0)
                {
                    col[y].insert(c);
                    row[x].insert(c);
                    grid[rig].insert(c);
                    board[x][y] = c;
                    if (ok |= dfs(x, y + 1, board))
                    {
                        return true;
                    }
                    else
                    {
                        col[y].erase(c);
                        row[x].erase(c);
                        grid[rig].erase(c);
                    }
                }
            }
            return false;
        }
        else
        {
            dfs(x, y + 1, board);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
