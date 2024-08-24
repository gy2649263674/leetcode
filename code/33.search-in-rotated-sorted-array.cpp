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
    int search(vector<int> &nums, int& target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        auto it = upper_bound(nums.begin(), nums.end(), nums[0], greater<int>());
        // 1 2 3 4 5 6
        if (it == nums.end())
        {
            auto tmp = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
            return tmp == nums.end()-nums.begin() ? -1 : (nums[tmp] == target? tmp : -1);
        }
        // 4 5 6 1 2 3
        else
        {
            int maxn = it - nums.begin();
            auto tmp = lower_bound(nums.begin(), it, target) - nums.begin();
            if (tmp < maxn&&nums[tmp] == target)
            {
                return tmp;
            }
            else
            {
                tmp = lower_bound(it, nums.end(), target) - it;
                maxn = nums.end() - it;
                if (tmp < maxn && nums[tmp + it - nums.begin()] == target)
                {
                    return tmp + it - nums.begin();;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout<<s.search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 0);
}
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
