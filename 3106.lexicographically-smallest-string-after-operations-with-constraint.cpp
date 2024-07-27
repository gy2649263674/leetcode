/*
 * @lc app=leetcode.cn id=3106 lang=cpp
 * @lcpr version=30204
 *
 * [3106] 满足距离约束且字典序最小的字符串
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
    string getSmallestString(string s, int k)
    {
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            int m = min(s[i] - 'a', 'z' + 1 - s[i]);
            if (k < m)
            {
                s[i] -= k;
                break;
            }
            else
            {
                s[i] = 'a';
            }
            k -= m;
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "zbbz"\n3\n
// @lcpr case=end

// @lcpr case=start
// "xaxcd"\n4\n
// @lcpr case=end

// @lcpr case=start
// "lol"\n0\n
// @lcpr case=end

 */
