/*
 * @lc app=leetcode.cn id=2860 lang=cpp
 * @lcpr version=30204
 *
 * [2860] 让所有学生保持开心的分组方法数
 */
// for (int i = 0; i < (1<<n); i++)
//     {
//         int ch = bit(i);
//         bool flag = true;
//         for (int j = 0; j < n; j++)
//         {
//             if(i&(1<<j))
//             {
//                 if(ch<=nums[j])
//                 {
//                     flag = false;
//                 }
//             }
//             else
//             {
//                 if(ch>= nums[j])
//                 {
//                     flag = false;
//                 }
//             }
//         }
//         ans += flag;
//     }
//     //all in
//     //n>max
//     // int ex = *max_element(nums.begin(),nums.end())<n;
//     // ex+=(*min_element(nums.begin(),nums.end()))>n;
//     return ans;
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
    int bit(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            n -= (n & (-n));
            ++ans;
        }
        return ans;
    }

    int countWays(vector<int>& nums)
    {
        // stu with same val must be the same state!!!!
        //  if the choosed is not successive  then :
        //  will cause the n>nums[i+1] and n<nums[i]
        // but nums[i]<nums[i+1]
        // 0 2 3 3 6 6 7 7
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (i + 1 > nums[i] && i + 1 < nums[i + 1])
            {
                ++ans;
            }
        }
        // all in
        ans += nums.back() < n;
        ans += *nums.begin() > 0;
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.countWays({1, 1});
    return 0;
}
/*
// @lcpr case=start
// [1,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,0,3,3,6,7,2,7]\n
// @lcpr case=end

 */
