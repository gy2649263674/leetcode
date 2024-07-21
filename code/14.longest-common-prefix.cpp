/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30204
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string> &strs)
    {
        int ans = 0;
        int l = 0, r =200;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            bool ok = true;
            auto ss = strs.begin()->substr(0, mid);
            for (auto &it : strs)
            {
                if (it.length() < mid || it.substr(0, mid) != ss)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return strs.begin()->substr(0, ans);
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
