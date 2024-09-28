/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 * @lcpr version=30204
 *
 * [2306] 公司命名
 *
 * https://leetcode.cn/problems/naming-a-company/description/
 *
 * algorithms
 * Hard (44.78%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 13.5K
 * Testcase Example:  '["coffee","donuts","time","toffee"]'
 *
 * 给你一个字符串数组 ideas 表示在公司命名过程中使用的名字列表。公司命名流程如下：
 *
 *
 * 从 ideas 中选择 2 个 不同 名字，称为 ideaA 和 ideaB 。
 * 交换 ideaA 和 ideaB 的首字母。
 * 如果得到的两个新名字 都 不在 ideas 中，那么 ideaA ideaB（串联 ideaA 和 ideaB
 * ，中间用一个空格分隔）是一个有效的公司名字。
 * 否则，不是一个有效的名字。
 *
 *
 * 返回 不同 且有效的公司名字的数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：ideas = ["coffee","donuts","time","toffee"]
 * 输出：6
 * 解释：下面列出一些有效的选择方案：
 * - ("coffee", "donuts")：对应的公司名字是 "doffee conuts" 。
 * - ("donuts", "coffee")：对应的公司名字是 "conuts doffee" 。
 * - ("donuts", "time")：对应的公司名字是 "tonuts dime" 。
 * - ("donuts", "toffee")：对应的公司名字是 "tonuts doffee" 。
 * - ("time", "donuts")：对应的公司名字是 "dime tonuts" 。
 * - ("toffee", "donuts")：对应的公司名字是 "doffee tonuts" 。
 * 因此，总共有 6 个不同的公司名字。
 *
 * 下面列出一些无效的选择方案：
 * - ("coffee", "time")：在原数组中存在交换后形成的名字 "toffee" 。
 * - ("time", "toffee")：在原数组中存在交换后形成的两个名字。
 * - ("coffee", "toffee")：在原数组中存在交换后形成的两个名字。
 *
 *
 * 示例 2：
 *
 * 输入：ideas = ["lack","back"]
 * 输出：0
 * 解释：不存在有效的选择方案。因此，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= ideas.length <= 5 * 10^4
 * 1 <= ideas[i].length <= 10
 * ideas[i] 由小写英文字母组成
 * ideas 中的所有字符串 互不相同
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
#include <map>
#include <vector>
#include <set>
// @lcpr-template-end
// @lc code=start
// #include <bits/stdc++.h>
#include <bitset> // Add this include for std::bitset

class Solution
{
public:
    // get the sub of to set quickly
    long long distinctNames(vector<string> &ideas)
    {
        set<string> mp[26]{};
        for (auto s : ideas)
        {
            auto suf = s.substr(1, s.length() - 1);
            mp[s[0] - 'a'].insert(suf);
            // mp[suf] |= 1 << (s[0] - 'a');
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = i; j < 26; j++)
            {
                int cnt = 0;
                for (const string &str : mp[i])
                {
                    cnt += mp[j].count(str);
                }
                ans += (mp[i].size() - cnt) * 1ll * (mp[j].size() - cnt);
            }
        }
        return ans * 2;
        // function<long long(int, int)> cal = [=](int a, int b) -> long long
        // {
        //     if (!a || !b)
        //     {
        //         return 0;
        //     }
        //     int same = bitset<32>(a & b).count();
        //     int a1 = bitset<32>(a).count();
        //     int b1 = bitset<32>(b).count();
        //     return (b1 - same) * (a1 - same);
        // };
        // // int tot = mp.size();
        // for (map<string, int>::iterator i = mp.begin(); i != mp.end(); i++)
        // {
        //     for (auto j = next(i); j != mp.end(); j++)
        //     {
        //         ans += cal(i->second, j->second);
        //     }
        // }
        // return ans * 2;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout << s.distinctNames({"aaa", "baa", "caa", "bbb", "cbb", "dbb"});
    return 0;
}
/*
// @lcpr case=start
// ["coffee","donuts","time","toffee"]\n
// @lcpr case=end

// @lcpr case=start
// ["lack","back"]\n
// @lcpr case=end

 */
