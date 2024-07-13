/*
 * @lc app=leetcode.cn id=2741 lang=cpp
 * @lcpr version=30204
 *
 * [2741] 特别的排列
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
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1<<n));
        for(int i = 1;i<=n;i++)
        {
            for(int j = 0;j<=(1<<n)-1;j++)
            {
                if(j&1<<i)
                {
                    for(int k = 1;k<i;k++)
                    {
                        if(arr[i][])
                    }
                }
            }
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3]\n
// @lcpr case=end

 */

