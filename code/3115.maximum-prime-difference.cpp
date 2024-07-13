/*
 * @lc app=leetcode.cn id=3115 lang=cpp
 * @lcpr version=30204
 *
 * [3115] 质数的最大距离
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
    vector<int> pri;
    vector<bool> is;
    void oula(int n)
    {
        is = vector<bool>(n + 1, 1);
        is[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (is[i])
            {
                pri.push_back(i);
            }
            for (auto j : pri)
            {
                if (i * j > n)
                {
                    break;
                }
                is[i * j] = false;
                if (j % i == 0)
                {
                    break;
                }
            }
        }
    }
    int maximumPrimeDifference(vector<int> &nums)
    {
        oula(120);
        int l = 0,r = nums.size()-1;
        while(l<= r)
        {
            if(is[nums[l]] == true)
            {
                break;
            }
            l++;
        }
        while(r>=l)
        {
            if(is[nums[r]] ==  true)
            {
                break;
            }
            r--;
        }
        return r-l;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    vector<int>arr{4,8,2,8};
    cout<<s.maximumPrimeDifference(arr);
    return 0;

}
/*
// @lcpr case=start
// [4,2,9,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,2,8]\n
// @lcpr case=end

 */
