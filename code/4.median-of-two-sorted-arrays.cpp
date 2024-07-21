/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
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
class Solution
{
public:
    double k_st(int k, vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = 0, s2 = 0;
        while (1)
        {
            int delt = k / 2 - 1;
            if (s1 == nums1.size())
            {
                return nums2[s2 + k - 1];
            }
            if (s2 == nums2.size())
            {
                return nums1[s1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[s1], nums2[s2]);
            }

            int in1 = min(s1 + delt, int(nums1.size() - 1));
            int in2 = min(s2 + delt, int(nums2.size() - 1));
            if (nums1[in1] <= nums2[in2])
            {
                k -= in1 - s1 + 1;
                s1 = in1 + 1;
            }
            else if (nums1[in1] > nums2[in2])
            {
                k -= in2 - s2 + 1;
                s2 = in2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
    {
        if ((nums1.size() + nums2.size()) % 2 == 1)
        {
            return k_st((1 + nums1.size() + nums2.size()) / 2, nums1, nums2);
        }
        else
        {
            return (k_st((nums1.size() + nums2.size()) / 2, nums1, nums2) +
                    k_st((nums1.size() + nums2.size()) / 2 + 1, nums1, nums2)) /
                   2.0;
        }
    }
};
// {
// public:
//     double find(int tar, vector<int>& nums1, vector<int>& nums2)
//     {
//         int n = nums1.size(), m = nums2.size();
//         int l = 0, r = nums2.size();
//         while (l <= r)
//         {
//             int mid = l + r >> 1;
//             auto it = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
//             if (mid + it> tar)
//             {
//                 r = mid - 1;
//             }
//             else if (mid + it< tar)
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 return 1.0 * nums2[mid];
//             }
//         }
//         l = 0, r = nums1.size() - 1;
//         while (l <= r)
//         {
//             int mid = l + r >> 1;
//             auto it = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
//             if (mid + it  > tar)
//             {
//                 r = mid - 1;
//             }
//             else if (mid + it  < tar)
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 return 1.0 * nums1[mid];
//             }
//         }
//         return 0;
//     }
//     double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
//     {
//         int m = nums1.size(), n = nums2.size();
//         if (m + n & 1)
//         {
//             return find(m + n >> 1, nums1, nums2);
//         }
//         else
//         {
//             return (find(m + n-1 >> 1, nums1, nums2) + find((m + n >> 1) , nums1, nums2)) / 2.0;
//         }
//     }
// };
// @lcpr-template-end

// @lc code=start
//
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */
