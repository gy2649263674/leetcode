/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
 */
#define BUG
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
    void rotate(vector<vector<int>>&matrix)
    {
        int n = matrix.size();
        // A[][]
        for (int i = 0; i <  n / 2; i++)
        {
            //内圈
            for (int j = i; j < n-i-1; j++)
            {
                // int tmp = matrix[j][n - i - 1];
                // i,j
                //  j = (n-i-1), i = j
                // always iteration
                int tmp = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[i][j];
                // matrix[i][j] = matrix[n-j-1][i]
                matrix[i][j] = tmp;
                #ifdef BUG
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << matrix[i][j] << " ";
                    }
                    cout << endl;
                }
                cout<<endl<<endl;
                #endif
            }
        }
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    // s.rotate({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    s.rotate({{5,1,9,11}
    ,{2,4,8,10},
    {13,3,6,7},
    {15,14,12,16}});

    return 0;
}
/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */
