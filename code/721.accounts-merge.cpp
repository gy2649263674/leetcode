/*
 * @lc app=leetcode.cn id=721 lang=cpp
 * @lcpr version=30204
 *
 * [721] 账户合并
 */
// for (int i = 0; i < n; i++)
//  {
//      auto name = accounts[i][0];
//      for (auto &it : accounts[i])
//      {
//          mp[name].insert(it);
//      }
//  }
//  vector<vector<string>> ans;
//  int cnt = 0;
//  for (auto &[name_, mail] : mp)
//  {
//      ans.push_back(vector<string>());
//      for (auto &it : mail)
//      {
//          ans[cnt].push_back(it);
//      }
//      ++cnt;
//  }
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
#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts)
    {
        int n = accounts.size();
        map<string, vector<set<string>>> mp;
        for (int i = 0; i < n; i++)
        {
            auto name = accounts[i][0];
            mp[name].push_back({});
            for (auto &it : accounts[i])
            {
                if (it != name)
                    mp[name].back().insert(it);
            }
        }
        vector<vector<int>> temp;
        vector<vector<string>> ans;
        for (auto [name, mails] : mp)
        {
            int tmpn = mails.size();
            vector<bool> vis(tmpn, false);
            // merge set
            // mails = vector<set>
            for (int i = 0; i < tmpn; i++)
            {
                vis[i] = true;
                for (int j = 0; j < tmpn; j++)
                {
                    if (j != i)
                        for (auto &var : mails[i])
                        {
                            if (mails[j].count(var))
                            {
                                mails[i].insert(mails[j].begin(), mails[j].end());
                                vis[j] = true;
                                mails[j].clear();
                                break;
                            }
                        }
                }
            }
            for (auto act : mails)
            {
                int nums = act.size();
                if (nums != 0)
                {
                    ans.push_back({});
                    ans.back().push_back(name);
                    for (auto &email : act)
                    {
                        ans.back().push_back(email);
                    }
                    sort(ans.back().begin() + 1, ans.back().end());
                }
            }
        }
        return ans;
    }
};
//"John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"
// int main(void)
// {

//     Solution ss;
//     ss.accountsMerge({{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
//                       {"John", "johnsmith@mail.com", "john00@mail.com"},
//                       {"Mary", "mary@mail.com"},
//                       {"John", "johnnybravo@mail.com"}});
//                       return 0;
// }
// @lc code=end

/*
// @lcpr case=start
// [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John","johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]\n
// @lcpr case=end

// @lcpr case=start
// [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]\n
// @lcpr case=end

 */
