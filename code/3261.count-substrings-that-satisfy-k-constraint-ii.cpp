/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 * @lcpr version=30204
 *
 * [3261] 统计满足 K 约束的子字符串数量 II
 *
 * https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/description/
 *
 * algorithms
 * Hard (41.42%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 6.2K
 * Testcase Example:  '"0001111"\n2\n[[0,6]]'
 *
 * 给你一个 二进制 字符串 s 和一个整数 k。
 *
 * 另给你一个二维整数数组 queries ，其中 queries[i] = [li, ri] 。
 *
 * 如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
 *
 *
 * 字符串中 0 的数量最多为 k。
 * 字符串中 1 的数量最多为 k。
 *
 *
 * 返回一个整数数组 answer ，其中 answer[i] 表示 s[li..ri] 中满足 k 约束 的 子字符串 的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "0001111", k = 2, queries = [[0,6]]
 *
 * 输出：[26]
 *
 * 解释：
 *
 * 对于查询 [0, 6]， s[0..6] = "0001111" 的所有子字符串中，除 s[0..5] = "000111" 和 s[0..6] =
 * "0001111" 外，其余子字符串都满足 k 约束。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
 *
 * 输出：[15,9,3]
 *
 * 解释：
 *
 * s 的所有子字符串中，长度大于 3 的子字符串都不满足 k 约束。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 是 '0' 或 '1'
 * 1 <= k <= s.length
 * 1 <= queries.length <= 10^5
 * queries[i] == [li, ri]
 * 0 <= li <= ri < s.length
 * 所有查询互不相同
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
{ // vector<long long> countKConstraintSubstrings0(string s, int k, vector<vector<int>> &queries)
  // {
  //     int n = s.length();
  //     vector<long long> ans;
  //     vector<int> pre0(s.size() + 1), pre1(s.size() + 1);
  //     vector<int> able(n, n - 1);
  //     for (int i = 0; i < s.size(); i++)
  //     {
  //         pre0[i + 1] = pre0[i] + (s[i] == '0');
  //         pre1[i + 1] = pre1[i] + (s[i] == '1');
  //         // able[i];3260
  //     }
  //     for (int i = 0; i < n; i++)
  //     {
  //         auto i0 = upper_bound(pre0.begin(), pre0.end(), pre0[i] + k) - pre0.begin();
  //         auto i1 = upper_bound(pre1.begin(), pre1.end(), pre1[i] + k) - pre1.begin();
  //         if (i0 != n + 1 && i1 != n + 1)
  //         {
  //             able[i] = max(i0, i1) - 2;
  //         }
  //     }
  //     for (auto &q : queries)
  //     {
  //         long long tmp = 0;
  //         for (int i = q[0]; i <= q[1]; i++)
  //         {
  //             tmp += min(able[i] - i, q[1] - i) + 1;
  //             cout << min(able[i] - i, q[1] - i) + 1;
  //         }
  //         cout << endl;
  //         ans.push_back(tmp);
  //     }
  //     return ans;
  // }
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
    {
        auto cal = [](int l, int r) -> long long 
        {
            return abs((r - l + 1ll) * (r - l)) / 2 + r - l + 1;
            // any sub arr has start and end 
            // only one element 
            
        };
        // calculate the left boundary of each right
        // remember the left boundary of each right
        //  if the left is right then the q[0] then all the val of rigth is
        //  if the left[i]<q[0] the just (q[0] to i ) is all valid
        int c0 = 0, c1 = 0;
        int n = s.length();
        vector<int> left(n);
        vector<long long> ans;
        vector<long long> pre(n + 1);
        for (int l = 0, r = 0; r < s.size(); r++)
        {
            c0 += s[r] == '0';
            c1 += s[r] == '1';
            while (c0 > k && c1 > k)
            {
                c0 -= s[l] == '0';
                c1 -= s[l] == '1';
                l++;
            }
            left[r] = l;
            pre[r + 1] = pre[r] + (r - l + 1);
        }
        // for(int i = )

        for (auto &q : queries)
        {
            int r = q[1], l = q[0];
            if (left[r] <= l)
            {
                ans.push_back(cal(l, r));
            }
            else
            {
                auto bound = upper_bound(left.begin(), left.end(), l) - left.begin() - 1;
                long long  tmp = cal(l, bound);
                tmp += pre[r + 1] - pre[bound + 1];
                ans.push_back(tmp);
                // the left must be increasing
                // cal who's left is less than l
                // bound to r
                // left[bound] to left[r] must bigger then l and small then r
                // then accumulate the all i - left[i]+1;
            }
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
    vector<vector<int>> queries = {{0, 5}, {1, 4}, {2, 3}};
    string s = "010101";
    int k = 1;
    auto ans = sol.countKConstraintSubstrings(s, k, queries);
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
/*
// @lcpr case=start
// "0001111"\n2\n[[0,6]]\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n1\n[[0,5],[1,4],[2,3]]\n
// @lcpr case=end

 */
