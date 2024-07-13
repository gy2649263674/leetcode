/*
 * @lc app=leetcode.cn id=3132 lang=cpp
 *
 * [3132] 找出与数组相加的整数 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool able(multiset<int> s1, multiset<int> s2, int mid) //(vector<int>&nums1,vector<int>&nums2,int mid)
    {
        bool vis[1000];
        int cn = 0;
        for (int var : s2)
        {
            if (s1.count(var-mid))
            {
                s1.erase(s1.lower_bound(var-mid));
            }
            else
            {
                return false;
            }

        }
        return  1;
    }
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        multiset<int> s1(nums1.begin(), nums1.end());
        multiset<int> s2(nums2.begin(), nums2.end()); 
        for (int i = 0; i > -1000; i++)
        {
            if (able(s1, s2, i))
            {
                return -i;
            }
        }
        for (int i = 0; i < 1000; i++)
        {
            if (able(s1, s2, i))
            {
                return i;
            }
        }
        
        
        return 1;
    }
};
// @lc code=end

int main(void)
{
 Solution s;
 vector<int>s1 = {3 ,3,5,5};
vector<int>s2 =  {7,7};
 cout<<s.minimumAddedInteger(s1,s2);
 return 0;

}