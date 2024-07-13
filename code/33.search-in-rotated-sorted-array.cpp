/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();
        int ans = 0, mval = arr[n / 2];
        int pos = 0;
        if (arr.back() > ans)
        {
            // left
            int l = 0, r = n / 2;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (arr[mid] > mval)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                    pos = r;
                }
            }
        }
        else
        {
            int l = 0, r = n / 2;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (arr[mid] > mval)
                {
                    pos = l;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        pos = min(n - 1, pos);
        pos = max(pos, -1);
        auto it = lower_bound(arr.begin(), arr.begin() + pos + 1, target);
        auto it2 = lower_bound(arr.begin() + pos)
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
