/*
 * @lc app=leetcode.cn id=698 lang=cpp
 * @lcpr version=30204
 *
 * [698] 划分为k个相等的子集
 */

// @lcpr-template-start
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 * @lcpr version=30204
 *
 * [698] 划分为k个相等的子集
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
#include <unordered_unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include "E:\zzs\gy\cpp\stdc++.h"

// @lcpr-template-end
// @lc code=start
class Solution
{
    bool state[1 << 17] = {false};

public:
    int tarl = 0, tarn, q;
    bool dfs(int sta, int n, int pre, vector<int> &nums)
    {
        if (sta == 0)
        {
            // 不会有总和大于tarl地情况，sta == 0时一定是均匀的分布
            return true;
        }
        if (state[sta])
        {
            // if pre1 != pre2
            // turl = x
            // sum = ax+b = cx+d
            // b-d = (a-c)x = kx;
            // ax = (c+k)x
            // a = c+k
            // b<x,d<x ,b-d<x=>c = 0=>a = c
            // state is enough to ensure
            // a state only have to be visit for a time
            return false;
        }
        state[sta] = true;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] + pre > tarl)
            {
                break;
            }
            if ((sta & (1 << i)))
            {
                q = ~(1 << i);
                ans |= dfs(sta ^ (1 << i), n, (pre + nums[i]) % tarl, nums);
                if (!ans)
                {
                    i = nex[i];
                }
                else
                {
                    return true;
                }
                if (pre == 0 && ans == false)
                {
                    return false;
                }
            }
        }
        return ans;
    }
    int nex[20];
    bool canPartitionKSubsets(vector<int> nums, int k)
    {
        int n = nums.size();
        int dp[1 << 17];
        int pre[1 << 17];
        for (int i = 0; i <= -1 + (1 << n); i++)
        {
            // dp[sta]
            for (int j = 0; j < n; j++)
            {
                if (pre[i] + nums[j] > tarl)
                {
                    break;
                }
                else
                {
                    int to = i | (1 << j);
                    // pre[i] is used to limit which can be used to tran
                    // when pre[i] +                        
                    if (i & (1 << j) == 0)
                    {
                        pre[i] = (pre[to] + nums[j]) % tarl;
                    }
                }
            }
            return dp[];
        }
    }
    bool canPartitionKSubsets1(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());
        int next = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            nex[i] = next;
            if (nums[i - 1] != nums[i])
            {
                next = i - 1;
            }
        }
        nex[0] = nums[1] == nums[0] ? nex[1] : 0;
        tarn = k;
        tarl = accumulate(nums.begin(), nums.end(), tarl);
        if (tarl % k)
        {
            return false;
        }
        tarl /= k;
        if (nums.back() > tarl)
        {
            return false;
        }
        return dfs(-1 + (1 << nums.size()), 0, 0, nums);
    }
};
rand() - 11 22 3 23 4  45
random(seed)
rand() - 11 

// @lc code=end
int main(void)
{
    frand
    Solution s;
    for (int i = 0; i < (1 << 17); i++)
    {
        state[i] = unordered_map<int, bool>();
    }
    cout << s.canPartitionKSubsets({4, 3, 2, 3, 5, 2, 1}, 4);
    return 0;
}

/*
// @lcpr case=start
// [4, 3, 2, 3, 5, 2, 1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n3\n
// @lcpr case=end

 */
