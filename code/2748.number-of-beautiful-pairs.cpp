/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 * @lcpr version=30204
 *
 * [2748] 美丽下标对的数目
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
    int gcd(int a, int b)
    {
        return a % b == 0 ? b : gcd(b, a % b);
    }
    int countBeautifulPairs(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int t1, t2;
            for (int j = i + 1; j < nums.size(); j++)
            {
                string s;
                s = to_string(nums[i]);
                t1 = s[0] - '0';
                t2 = nums[j] % 10;
                if (gcd(t1, t2) == 1)
                    ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,5,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,21,12]\n
// @lcpr case=end

 */
