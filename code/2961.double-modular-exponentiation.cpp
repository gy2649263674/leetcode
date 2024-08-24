/*
 * @lc app=leetcode.cn id=2961 lang=cpp
 * @lcpr version=30204
 *
 * [2961] 双模幂运算
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
    int pow(int a, int b, int m)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
            {
                ans = (ans * a) % m;
            }
            b >>= 1;
            a = a * a % m;
        }
        return ans;
    }
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++)
        {
            if (target == pow(pow(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3]))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,3,3,10],[3,3,3,1],[6,1,1,4]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[39,3,1000,1000]]\n17\n
// @lcpr case=end

 */
