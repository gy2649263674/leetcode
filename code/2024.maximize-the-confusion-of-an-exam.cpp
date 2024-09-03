/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 * @lcpr version=30204
 *
 * [2024] 考试的最大困扰度
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
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(maxsame(answerKey,k,'T'),maxsame(answerKey,k,'F'));
        
        int n = answerKey.length();
        int c = 0;
        int ans = 0;
        for (int i = 0, j = 0; j < n;)
        {
            if (answerKey[j] == 'T')
            {
                j++;
            }
            else
            {
                c++;
                j++;
            }
            if (c > k)
            {
                while (answerKey[i] != 'F')
                {
                    ++i;
                }
                ++i;
                c--;
            }
            ans = max(ans, j - i);
        }
        c = 0;
        for (int i = 0, j = 0; j < n;)
        {
            if (answerKey[j] == 'F')
            {
                j++;
            }
            else
            {
                c++;
                j++;
            }
            if (c > k)
            {
                while (answerKey[i] != 'T')
                {
                    ++i;
                }
                ++i;
                c--;
            }
            
            ans = max(ans, j - i);
        }
        return ans;
    }
    int maxsame(string &s,int k,char ch)
    {
        int l = 0,r = 0;
        int n = s.length();
        int ans = 0,diff = 0;
        while(r<n)
        {
            diff+= s[r++]!= ch;
            while(diff>k)
            {
                diff-=s[l++]!= ch;
            }
            ans = max(ans,r-l);
        }
        // while(r<n)
        // {
        //     if(s[r++]!= ch)
        //     {
        //         ++diff;
        //     }
        //     while(diff>k&&s[l] == ch)
        //     {
        //         ++l;
        //     }
        //     ans = max(ans,r-l);
        // }
        return ans;
    }
};

// end with F
// @lc code=end
int main(void)
{
    Solution s;
    cout<<s.maxConsecutiveAnswers("TTFTTFTT",1);
    return 0;

}
/*
// @lcpr case=start
// "TTFF"\n2\n
// @lcpr case=end

// @lcpr case=start
// "TFFT"\n1\n
// @lcpr case=end

// @lcpr case=start
// "TTFTTFTT"\n1\n
// @lcpr case=end



 */



//         int dp[10000][100];
//         // end with T
//         int ans = 0;
//         dp[0][0] = answerKey[0] == 'T' ? 1 : 0;
//         // for()
//         for (int i = 1; i < answerKey.length(); i++)
//         {
//             for (int j = 1; j <=k ; j++)
//             {
//                 // dp[i][k]  and changed i times;
//                 if (answerKey[i] == 'F')
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else // used j times =
//                     dp[i][j] = dp[i - 1][j] + 1;
//                 ans = max(ans, dp[i][j]);
//             }
//         }
// #include <string.h>
//         memset(dp, 0, sizeof(dp));
//         dp[0][0] = answerKey[0] == 'F' ? 1 : 0;

//         for (int i = 1; i < answerKey.length(); i++)
//         {
//             for (int j = 1; j <= k; j++)
//             {
//                 // dp[i][k]  and changed i times;
//                 if (answerKey[i] == 'T')
//                     dp[i][j] = dp[i - dp[i - 1][j - 1]][j - 1];
//                 else // used j times =
//                     dp[i][j] = dp[i - 1][j] + 1;
//                 ans = max(ans, dp[i][j]);
//             }
//         }
