/*
 * @lc app=leetcode.cn id=3011 lang=cpp
 * @lcpr version=30204
 *
 * [3011] 判断一个数组是否可以变为有序
 */

// for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n - i - 1; j++)
//             {
//                 if (arr[j].second == arr[j + 1].second && arr[j].first > arr[j + 1].first)
//                 {
//                     swap(arr[j], arr[j + 1]);
//                 }
//             }
//         }
//         for (int i = 0; i + 1 < n; i++)
//         {
//             if (arr[i + 1].first < arr[i].first)
//             {
//                 return false;
//             }
//         }
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
    int cnt(int n)
    {
        return __builtin_popcount(n);
    }
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        int premax = 0;
        int nowmax = premax;
        for (int i = 0; i + 1 < n; i++)
        {
            nowmax = max(nowmax, nums[i]);
            if (nums[i] < premax)
            {
                return false;
            }
            if (cnt(nums[i]) != cnt(nums[i + 1]))
            {
                premax = nowmax;
            }
        }
        return nums.back() >= premax;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,4,2,30,15]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,16,8,4,2]\n

// @lcpr case=end
 */