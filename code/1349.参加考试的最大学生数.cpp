/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
int dp[20][1 << 20] = {0};
using namespace std;
class Solution
{
public:
    int dfs(int sta, int cur, int pre, vector<vector<int>> &sts)
    {
        if (cur >= sts.size())
        {
            return 0;
        }
        if (dp[cur][sta]!= 0)
        {
            return dp[cur][sta];
        }
        else
        {
            int ans = 0; // dfs(0, cur + 1, 0, sts);
            for (int i = 0; i < 1 << sts[cur].size(); i++)
            {
                int now = 0;
                int cnt = 0;
                for (int j = 0; j < sts[cur].size(); j++)
                {
                    if ((i & (1 << j)) != 0)
                    {
                        now |= 1 << sts[cur][j];
                        ++cnt;
                    }
                }
                if ((now & (sta >> 1)) == 0 && (now & (sta << 1)) == 0 && (now & now << 1) == 0 && (now & now >> 1) == 0)
                {
                    ans = max(dfs(now, cur + 1, pre + cnt, sts) + cnt, ans);
                }
            }
            return dp[cur][sta] = ans;
        }
    }
    int maxStudents(vector<vector<char>> &st)
    {
        vector<vector<int>> arr(st.size());
        for (int i = 0; i < st.size(); i++)
        {
            for (int j = 0; j < st[i].size(); j++)
            {
                if (st[i][j] == '.')
                {
                    arr[i].push_back(j);
                }
            }
        }
        return dfs(0, 0, 0, arr);
    }
};

// @lc code=end
