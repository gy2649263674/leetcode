/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 * @lcpr version=30204
 *
 * [1450] 在既定时间做作业的学生人数
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
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int n = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            if ((queryTime - startTime[i]) * (queryTime - endTime[i]) <= 0)
            {
                ++n;
            }
        }
        return n;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[3,2,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [4]\n[4]\n4\n
// @lcpr case=end

// @lcpr case=start
// [4]\n[4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n[1,3,2,4]\n7\n
// @lcpr case=end

// @lcpr case=start
// [9,8,7,6,5,4,3,2,1]\n[10,10,10,10,10,10,10,10,10]\n5\n
// @lcpr case=end

 */
