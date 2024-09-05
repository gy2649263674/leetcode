/*
 * @lc app=leetcode.cn id=36 lang=cpp
 * @lcpr version=30204
 *
 * [36] 有效的数独
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
public:
    unordered_map<char, int> col[9], row[9], grid[9];
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
        return -1;
    }
    // bool dfs(int x, int y, vector<vector<char>> &board)
    // {
    //     if (x == 9)
    //     {
    //         return true;
    //     }
    //     if (y == 9)
    //     {
    //         return dfs(x + 1, 0, board);
    //     }
    //     int rig = get_ri(x, y);
    //     char c = board[x][y];
    //     if (col[y].count(c) + grid[rig].count(c) + row[x].count(c) > 1)
    //     {
    //         return dfs(x, y + 1, board);
    //     }
    //     return false;
    // }
    bool isValidSudoku(vector<vector<char>> board)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (++row[i][board[i][j]] > 1 ||
                        ++col[j][board[i][j]] > 1 ||
                        ++grid[get_ri(i, j)][board[i][j]] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
        // return dfs(0, 0, board);
    }
};

// @lc code=end

/*
// @lcpr case=start
// [["5',"3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

// @lcpr case=start
// [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
int main(void)
{
    Solution ss;
    vector<vector<char>> arr({vector<char>{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              vector<char>{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              vector<char>{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              vector<char>{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              vector<char>{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              vector<char>{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              vector<char>{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              vector<char>{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              vector<char>{'.', '.', '.', '.', '8', '.', '.', '7', '9'}});
    ss.isValidSudoku(arr);
}