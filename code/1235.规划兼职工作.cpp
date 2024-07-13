/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start

class Solution
{
public:
    struct dur
    {
        int s, e, val;
        dur(int s, int e, int val) : s(s), e(e), val(val){};
        dur() {}
    };

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<dur> time_(n);
        for (int i = 0; i < n; i++)
        {
            time_[i].s = startTime[i];
            time_[i].e = endTime[i];
            time_[i].val = profit[i];
        }
        sort(time_.begin(), time_.end(), [](const dur &a, const dur &b)
             { return a.e < b.e; });

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            auto it = upper_bound(time_.begin(), time_.begin() + i-1, time_[i - 1].s, [](const int &b, const dur &a)
                                  { return a.e < b; }) -
                      time_.begin();
            dp[i] = max(dp[i - 1], dp[it] + time_[i - 1].val);
        }
        return dp[n];
    }
};

// @lc code=end
