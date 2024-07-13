/*
 * @lc app=leetcode.cn id=1958 lang=cpp
 * @lcpr version=30204
 *
 * [1958] 检查操作是否合法
 */

// if ((!(np.x < m && np.y < n && np.x>=0 && np.y>=0)) || mp[np.x][np.y] == mp[a.x][a.y])
// {
//     while (rnp.x < m && rnp.y < n && rnp.x>=0 && rnp.y>=0 && mp[rnp.x][rnp.y] != mp[a.x][a.y]&&mp[rnp.x][rnp.y] !='.')
//     {
//         rnp = rnp - d[dir];
//         ++cnt;
//     }
//     return rnp.x < m && rnp.y < n && rnp.x>=0 && rnp.y>=0&&cnt>=2;
// }
// else if ((!(rnp.x < m && rnp.y < n && rnp.x>=0 && rnp.y>=0)) || mp[rnp.x][rnp.y] == mp[a.x][a.y])
// {
//     while (np.x < m && np.y < n &&np.x>=0 && np.y>=0&& mp[np.x][np.y] != mp[a.x][a.y]&&mp[np.x][np.y] !='.')
//     {
//         np = np + d[dir];
//         ++cnt;
//     }
//     return np.x < m && np.y < n &&np.x>=0 && np.y>=0&&cnt>=2;
// }
// return false;
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
    int m, n;

    vector<vector<char>> mp;
    int x[8] = {1,1,1,-1,-1,-1,0,0};
    int y[8] = {0,1,-1,0,1,-1,1,-1};

    // xia
    // you
    // youxia
    // zuoxia
    bool check(int dir, int r, int c, char ch)
    {
        bool op = false;
        int cnt = 0;
        r += x[dir];
        c += y[dir];
        while (r >= 0 && c >= 0 && r < 8 && c < 8)
        {
            if (mp[r][c] == ch)
            {
                return op;
            }
            else if (mp[r][c] != '.' && mp[r][c] != ch)
            {
                op = true;
            }
            else
            {
                return false;
            }
            r += x[dir];
            c += y[dir];
        }
        return false;
    }
    bool checkMove(vector<vector<char>> &mmp, int rMove, int cMove, char color)
    {
        mp = mmp;
        m = mp.size(), n = mp[0].size();
        mp[rMove][cMove] = color;
        for (int i = 0; i < 8; i++)
        {
            if (check(i, rMove, cMove, color))
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]]\n4\n3\n"B"\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]]\n4\n4\n"W"\n
// @lcpr case=end

 */
