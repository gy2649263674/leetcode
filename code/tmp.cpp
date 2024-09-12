#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumLength(vector<int> nums, int k)
    {
        //
        int dp[100000][50] = {0};
        dp[0][0] = 1;
        // memset(&dp[0], 1, sizeof(dp[0]));
        for (int i = 0; i = k; i++)
        {
            dp[0][i] = 1;
        }
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            // dp[i][j] = max(dp[i][j],dp[x][])
            // already has j diff in pre i
            for (int l = 0; l < i; l++)
            {
                // transs from l
                for (int j = 0; j < min(k, i); j++)
                {
                    dp[i][j] = max(dp[i][j], dp[l][j - (nums[l] != nums[i])] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i = k; i++)
        {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};
int main(void)
{
    Solution s;
    cout << s.maximumLength({3, 28, 30}, 0);
    return 0;
}