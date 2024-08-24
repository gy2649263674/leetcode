/*
 * @lc app=leetcode.cn id=357 lang=cpp
 * @lcpr version=30204
 *
 * [357] 统计各位数字都不同的数字个数
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
    // int violet(int n, int left)
    // {
    //     if (n == 1)
    //     {
    //         return left;
    //     }
    //     else
    //     {
    //         return left * violet(n - 1, left - 1);
    //     }
    // }
    int countNumbersWithUniqueDigits(int n)
    {
        if(n == 0)
        {
            return 1;
        }
        int ans = 1;
        //1 9 
        //2 9*9
        //3 9*9*8
        for(int i = 0,c = 9,t = 9;i<n;i++,c--)
        {
            ans+=t;
            t*=c;
        }
        return ans;
        for (int i = 1; i <= n; i++)
        {
            int tmp = 9;
            // high to low
            for (int j = 0, k = 9; j < i-1; j++)
            {
                tmp*= (k-j);
            }
            ans+=tmp;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */
