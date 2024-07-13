/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        //priority_queue<int> big;
        priority_queue<int, vector<int>, greater<int>> big;
        //最大的数中最小的
        //大数应该为小根堆
        for(int i = 0;i<nums.size();i++)
        {
            if(big.size()<k)
            {
                big.push(nums[i]);
            }
            else if(nums[i]>big.top())
            {
                //small.push(big.top());
                big.pop();
                big.push(nums[i]);
            }
        }
        return big.top();
    }
};
// @lc code=end
