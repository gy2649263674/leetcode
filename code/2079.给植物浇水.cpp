/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int wateringPlants(vector<int> &arr, int m)
    {
        int now = m;
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (now < arr[i])
            {
                ans += 2 *i+1;
                now = m-arr[i];
            }
            else
            {
                ans+= 1;
                now -= arr[i];
            }
        }
        return ans;
    }
};
// @lc code=end
