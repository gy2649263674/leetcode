/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         if(height.size()< 3)
//         {
//             return 0;
//         }
//         int l = height[1];
//         int r = height[height.size()-2];
//         int lmax = height[1];
//         int rmax = *(height.rbegin()-1);
//         int ans = 0;
//         while(l!= r)
//         {
//             if(lmax>rmax)
//             {
//                 ans+= max(rmax-height[r],0);
//                 r--;
//                 rmax= max(rmax,height[r]);
//             }
//             else if(rmax>lmax)
//             {
//                 ans+= max(lmax-height[l],0);
//                 l++;
//                 lmax = max(lmax,height[l]);
//             }
//             else
//             {
//                 l++;
//                 r--;
//             }
//         }
//     }
// };
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();
//         vector<int> lm(height.size());
//         vector<int> rm(height.size());
//         lm[0] = height[0];
//         rm[n - 1] = height[n - 1];
//         for (int i = 1; i < n; i++)
//         {
//             lm[i] = max(height[i], lm[i - 1]);
//         }
//         for (int i = n - 2; i >= 0; i--)
//         {
//             rm[i] = max(rm[i + 1], height[i]);
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             ans +=max(min(lm[i],rm[i])-height[i],0);
//         }
//         return ans;
//     }

// };
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if(n<=2)
        {
            return 0;
        }
        int l = 0, r = n - 1;
        int lm = height[l], rm = height[r];
       ///--r,++l;
        int ans = 0;
        while (l < r)
        {
            if (rm < lm)
            {
                ans += max(0, min(lm, rm) - height[r]);
                r--;
            }
            else
            {
                ans += max(0, min(lm, rm) - height[l]);
                l++;
            }
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);
        }
        return ans;
    }
};

// @lc code=end
