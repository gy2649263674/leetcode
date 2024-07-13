/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30204
 *
 * [80] 删除有序数组中的重复项 II
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
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0, r = 0;
        while (r != nums.size())
        {
            int pre = nums[r];
            int cnt= 0;
            while(r!= nums.size()&&nums[r] == pre)
            {
                cnt++;
                if(cnt<=2)
                {
                    nums[l++] = nums[r];
                }
                r++;
            }
        }
        return l;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
