/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 涓嬩竴涓帓鍒?
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
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return;
        }
        int i = n - 2;
        for (; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
            // 1 2 3 4 5
            // 3 4       5 2 1
        }
        if (i>=0)
        {
            int ind = i;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    // swap(nums[j], nums[i]);
                    ind = j;
                }
                else if (nums[j] < nums[i])
                {
                    break;
                }
            }
            swap(nums[i], nums[ind]);
        }
        sort(nums.begin() + i + 1, nums.end());
        return;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */
int main(void)
{
    Solution ss;
    vector<int> vec;
    ss.nextPermutation(vec = {1,3,2});
    for (int var : vec)
    {
        cout << var << " ";
    }
    return 0;
}