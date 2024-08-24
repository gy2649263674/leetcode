/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30204
 *
 * [682] 棒球比赛
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
    int calPoints(vector<string> &operations)
    {
        int s1 = 0, s2 = 0;
        vector<int>ans;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "+")
            {
                ans.push_back(*ans.rbegin()+*(ans.rbegin()+1));
            }
            else if (operations[i] == "D")
            {
                ans.push_back(ans.back()*2);
            }
            else if (operations[i] == "C")
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(atoi(&operations[i][0]));
            }
        }
        return range
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

 */
