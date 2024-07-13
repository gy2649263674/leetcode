/*
 * @lc app=leetcode.cn id=754 lang=cpp
 * @lcpr version=30204
 *
 * [754] 到达终点数字
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
    int reachNumber(int tar)
    {
        tar = tar < 0 ? -tar : tar;
        int i = 1;
        for (;; i++)
        {
            int val = i * (i + 1) / 2;
            if(val>=tar&&(val-tar)%2==0)
            {
                return i;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
