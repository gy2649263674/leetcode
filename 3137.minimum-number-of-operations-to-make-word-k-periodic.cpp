/*
 * @lc app=leetcode.cn id=3137 lang=cpp
 * @lcpr version=30204
 *
 * [3137] K 周期字符串需要的最少操作次数
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        int ans = 1e9;
        int len = word.length();
        for (int i = 0; i +k <= word.length(); i++)
        {
            if (i == 0||len % i == 0)
            {
                string ss = word.substr(i, k);
                int tmp =0;
                for (int j = 0; j+k < len; j += k)
                {
                    if (word.substr(j, k) !=ss)
                    {
                        ++tmp;
                    }
                }
                ans = min(ans,tmp);
            }
        }
        return ans;
        // map<string, int> mp;
        // for (int i = 0; i + k <= word.length(); i++)
        // {
        //     if(i== 0 || word.length()%i == 0)
        //         ++mp[word.substr(i, k)];
        // }
        // int ans = 1e9;
        // for (auto [_, val] : mp)
        // {
        //     ans = min(ans, static_cast<int>(word.length() - val*k)/k);
        // }
        // return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcodeleet"\n4\n
// @lcpr case=end

// @lcpr case=start
// "leetcoleet"\n2\n
// @lcpr case=end

 */

// int main(void)
// {
//     Solution s;
//     cout<<s.minimumOperationsToMakeKPeriodic("leetcodeleet", 4);
//     return 0;

// }