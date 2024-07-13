/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int violet()
    {
        
    }
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        // string ss1 =
        for(int i =             )
        if (s1.length() * n1 < s2.length() * n2)
        {
            return 0;
        }
        int c1 = 0,c2 = 0,p1 = 0,p2 = 0;
        while(1)
        {
            if()





        }

    }
};
// class Solution
// {
// public:
//     int violet()
//     {
        
//     }
//     int getMaxRepetitions(string s1, int n1, string s2, int n2)
//     {
//         // string ss1 =
//         for(int i =             )
//         if (s1.length() * n1 < s2.length() * n2)
//         {
//             return 0;
//         }
//         int ans = 0;
//         int T = 0;
//         int p1 = 0, p2 = 0;
//         int ma = 0;
//         for (; T < n1 * s1.length() && ma < n2;)
//         {
//             p1 = p1 == s1.length() ? 0 : p1;
//             while (p2 != s2.length() && T < n1 * s1.length() && p1 != s1.length())
//             {
//                 if (s1[p1] == s2[p2])
//                 {
//                     ++p2;
//                 }
//                 ++p1;
//                 ++T;
//             }
//             if (p2 == s2.length())
//             {
//                 ma++;
//                 p2 = 0;
//             }
//         }
//         if (ma == n2)
//         {
//             return n1 * s1.length() / T;
//         }
//         else
//         {
//             return 0;
//         }
//     }
// };
// @lc code=end
