/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30204
 *
 * [96] 不同的二叉搜索树
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
class Solution {
public:
    int numTrees(int n) {
        //1-root-1
        //dp[root] = dp[root]*dp[n-root-1]
        //dp[i] = ans
        //dp[n] = sum(dp[i]*dp[n-i-1])
        int dp[40] = {1};
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=i;j++)
            {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

