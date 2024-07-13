// /*
//  * @lc app=leetcode.cn id=LCP 61 lang=cpp
//  * @lcpr version=30204
//  *
//  * [LCP 61] 气温变化趋势
//  */
// class Solution
// {
// public:
//     int temperatureTrend(vector<int> &ta, vector<int> &tb)
//     {
//         int n = ta.size();
//         int cnt = 0;
//         int up = 0, down = 0, flat = 0, ans = 0;
//         for (int i = 1; i < n; i++)
//         {
//             if (ta[i] - ta[i - 1] > 0)
//             {
//                 ++up;
//                 if (down != 0)
//                 {
//                     int l = i - down;
//                     while (l<i&&tb[l] - tb[l - 1] < 0)
//                     {
//                         l++;
//                     }
//                     if (l == i)
//                     {
//                         ans = max(ans, down);
//                     }
//                     down = 0;
//                 }
//                 if (flat != 0)
//                 {
//                     int l = i - flat;
//                     while (l<i&&tb[l] - tb[l - 1] == 0)
//                     {
//                         l++;
//                     }
//                     if (l == i)
//                     {
//                         ans = max(ans, down);
//                         flat = 0;
//                     }
//                 }
//                 else if (l<i&&ta[i] - ta[i - 1] < 0)
//                 {
//                     ++down;
//                     if (up != 0)
//                     {
//                         int l = i - up;
//                         while (l<i&&tb[l] - tb[l - 1] > 0)
//                         {
//                             l++;
//                         }
//                         if (l == i)
//                         {
//                             ans = max(ans, down);
//                         }
//                         down = 0;
//                     }
//                     if (flat != 0)
//                     {
//                         int l = i - flat;
//                         while (l<i&&tb[l] - tb[l - 1] == 0)
//                         {
//                             l++;
//                         }
//                         if (l == i)
//                         {
//                             ans = max(ans, down);
//                             flat = 0;
//                         }
//                     }
//                     else
//                     {
//                         ++flat;
//                         if (up != 0)
//                         {
//                             int l = i - up;
//                             while (l<i&&tb[l] - tb[l - 1] > 0)
//                             {
//                                 l++;
//                             }
//                             if (l == i)
//                             {
//                                 ans = max(ans, down);
//                             }
//                             down = 0;
//                         }
//                         if (down != 0)
//                         {
//                             int l = i - down;
//                             while (l<i&&tb[l] - tb[l - 1] < 0)
//                             {
//                                 l++;
//                             }
//                             if (l == i)
//                             {
//                                 ans = max(ans, down);
//                             }
//                             down = 0;
//                         }
//                     }
//                 }
//             }
//         }
//     }
// };
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
//@lc code=start
class Solution
{
public:
    int temperatureTrend(vector<int> &ta, vector<int> &tb)
    {
        int n = ta.size();
        int ans = 0;
        int tmp = 0;
        for (int i = 1; i < n; i++)
        {

            int delt = ((ta[i] - ta[i - 1]) * (tb[i] - tb[i - 1]) > 0);
            if (delt > 0)
            {
                ++tmp;
            }
            else if ((ta[i] - ta[i - 1]) == 0&&(tb[i] - tb[i - 1]) == 0)
            {
                while ((ta[i] - ta[i - 1]) == 0&&(tb[i] - tb[i - 1]) == 0&&i<n)
                {
                    ++i;
                    ++tmp;
                }
                ans = max(tmp+1, ans);
            }
            else 
            {
                tmp = 0;
            }
            ans = max(tmp, ans);
        }
        return ans;
    }
};
// @lc code=end
// int main(void)
// {
//     vector<int> a{1, 2, 4, 4};
//     vector<int> b{2, 5, 57, 4};
//     s.temperatureTrend()
// }
/*
// @lcpr case=start
// [21,18,18,18\n[34,32,16,16,17]`>\n
// @lcpr case=end

// @lcpr case=start
// [5,10,16,-6,15,11\n[16,22,23,23,25,3,-16]`>\n
// @lcpr case=end

 */
