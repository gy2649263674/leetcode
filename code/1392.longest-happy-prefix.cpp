/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 * @lcpr version=30204
 *
 * [1392] 最长快乐前缀
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
    string longestPrefix(string s)
    {
        if(s.length() == 1)
        {
            return {};
        }
        int next[100000] = {0};
        for (int r = 1, l = 0; r < s.length(); r++)
        {
            if (s[l] == s[r])
            {
                l++;
                // [0,l)
                next[r] = l;
            }
            else{
                while(l!= 0&&s[l]!= s[r])
                {
                    l = next[l-1];
                }
                next[r] = s[l] == s[r]?++l:0;
            }
        }
        return s.substr(0,next[s.length()-1]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "level"\n
// @lcpr case=end

// @lcpr case=start
// "ababab"\n
// @lcpr case=end

 */
