/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30204
 *
 * [75] 颜色分类
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
    // 3 path
    void sortColors(vector<int> &nums)
    {
        int l = 0, m = 0, r = nums.size()-1;
        while (m <=r)
        {
            if (nums[m] < 1)
            {
                swap(nums[l++],nums[m++]);
            }
            // nums[l]>=1 ensure this than m can add and ignore the val swaped by l
            else if(nums[m]>1)
            {
                //here m can't add because can't 
                //ensure the value swaped to front is smaller than the std
                swap(nums[m],nums[r--]);
            }
            //l ... m ...r
            else{
                m++;
            }
        }
        return ;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */
