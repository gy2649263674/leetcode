/*
 * @lc app=leetcode.cn id=3164 lang=cpp
 * @lcpr version=30204
 *
 * [3164] 优质数对的总数 II
 *
 * https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/description/
 *
 * algorithms
 * Medium (30.31%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 21.7K
 * Testcase Example:  '[1,3,4]\n[1,3,4]\n1'
 *
 * 给你两个整数数组 nums1 和 nums2，长度分别为 n 和 m。同时给你一个正整数 k。
 *
 * 如果 nums1[i] 可以被 nums2[j] * k 整除，则称数对 (i, j) 为 优质数对（0 <= i <= n - 1, 0 <= j
 * <= m - 1）。
 *
 * 返回 优质数对 的总数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3,4], nums2 = [1,3,4], k = 1
 *
 * 输出：5
 *
 * 解释：
 *
 * 5个优质数对分别是 (0, 0), (1, 0), (1, 1), (2, 0), 和 (2, 2)。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2,4,12], nums2 = [2,4], k = 3
 *
 * 输出：2
 *
 * 解释：
 *
 * 2个优质数对分别是 (3, 0) 和 (3, 1)。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, m <= 10^5
 * 1 <= nums1[i], nums2[j] <= 10^6
 * 1 <= k <= 10^3
 *
 *
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
#include <queue>
#include <list>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
#include <set>
#include <map>
class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // set<int> st(mums1.);
        // unordered_map<int, int> st;
        int st[1000001] = {0};
        int st2[1000001] = {0};
        int mx = 0;
        bool flag = false;
        for (auto var : nums1)
        {
            if (var % k == 0)
            {
                ++st[(var / k)];
                mx = max(mx, var / k);
                flag = true;
                ;
            }
        }
        for (auto var : nums2)
        {
            ++st2[var];
        }
        if (!flag)
        {
            return 0;
        }
        long long ans = 0;
        // for (int i = 0; i < nums2.size(); i++)
        for (long long l = 1; l <= 1e6; l++)
        {
            if (st2[l] != 0)
                for (long long j = 1; j * l <= mx; j++)
                {
                    if (st[(j * l)])
                    {
                        ans += st[j * l] * 1ll * st2[l];
                    }
                }
        }
        return ans;
    }
};
// @lc code=end

int main(void)
{
    Solution s;
    cout << s.numberOfPairs({70, 70}, {6, 10}, 7);
    return 0;
}

/*
// @lcpr case=start
// [1,3,4]\n[1,3,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,12]\n[2,4]\n3\n
// @lcpr case=end

 */
