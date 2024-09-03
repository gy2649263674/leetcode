/*
 * @lc app=leetcode.cn id=3153 lang=cpp
 * @lcpr version=30204
 *
 * [3153] 所有数对中数位不同之和
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
    long long sumDigitDifferences(vector<int> &nums)
    {
        long long arr[10][10] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            int bit = 0;
            while (nums[i])
            {
                int cur = nums[i] % 10;
                ++arr[bit++][cur];
                nums[i] /= 10;
            }
        }
        long long ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = j+1; k < 10; k++)
                    ans += arr[i][k] * arr[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [13,23,12]\n
// @lcpr case=end

// @lcpr case=start
// [10,10,10,10]\n
// @lcpr case=end

 */
