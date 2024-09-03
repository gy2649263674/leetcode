/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 * @lcpr version=30204
 *
 * [2708] 一个小组的最大实力值
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
    long long maxStrength(vector<int> ori)
    {

        vector<long long> nums(ori.begin(), ori.end());

        long long minm[20] = {nums[0]};
        long long maxm[20] = {nums[0]};
        int n = nums.size();
        function<long long(void)> getans = [&](void) -> long long
        {
            long long p = 0, N = 0, z = 0, maxne = -1e9;
            long long tot = 1;
            for (int i = 0; i < n; i++)
            {
                long long num = nums[i];
                if (num != 0)
                {
                    tot =  tot * num;
                }
                if (num > 0)
                {
                    ++p;
                }
                else if (num < 0)
                {
                    ++N;
                    maxne = max(maxne, num);
                }
                else if (num == 0)
                {
                    ++z;
                }
            }
            if (n == 1)
            {
                return nums[0];
            }
            else
            {
                
                if (p == 0&&N<=1)//can't be only a negative
                {
                    return 0;
                }
                if (tot > 0)
                {
                    return tot;
                }
                if(tot<0)
                {
                    return tot/maxne;
                }
            }

            if (tot > 0)
            {
                return tot;
            }
            if (tot < 0)
            {
                int tmp = tot;
                for (int i = 0; i < n; i++)
                {
                    if (nums[i] != 0)
                    {
                        tot = max(tot, tmp / nums[i]);
                    }
                }
                if (tot < 0)
                {
                    return z == 0 ? tot : 0;
                }
                return tot == 1 ? (z == 0 ? tmp : 0) : tot;
                // //  return *max_element(nums.begin(),nums.end());
                // if(p == 0)
                // {
                //     return z == 0?tot:0;
                // }
                long long val = (tot / (*min_element(nums.begin(), nums.end())));
                return val == 1 ? tot : val;
            }
            return tot;
        };
        return getans();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > 0)
            {
                minm[i] = min({minm[i - 1] * nums[i], nums[i], minm[i - 1]});
                maxm[i] = max({maxm[i - 1] * nums[i], nums[i], maxm[i - 1]});
            }
            else if (nums[i] < 0)
            {
                minm[i] = min({maxm[i - 1] * nums[i], nums[i], minm[i - 1]});
                maxm[i] = max({minm[i - 1] * nums[i], nums[i], maxm[i - 1]});
            }
            else if (nums[i] == 0)
            {
                minm[i] = min(0ll, minm[i - 1]);
                maxm[i] = max(0ll, maxm[i - 1]);
            }
        }
        return maxm[n - 1];
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    s.maxStrength({0, -1});
    return 0;
}
/*
// @lcpr case=start
// [3,-1,-5,2,5,-9]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-5,-4]\n
// @lcpr case=end

 */
