/*

  * @lc app=leetcode.cn id=3040 lang=cpp

  * @lcpr version=30203

  *

  * [3040] 㼩稿怿㽒唿昿㼨刿渶漿ф搷浣渿昿㼩?II

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
    int (*dp)[2001];

    int solve(int l, int r, vector<int> &nums, const int tar)

    {

        if (l < 0 || r >= nums.size() || l >= r)

        {

            return 0;
        }

        if (dp[l][r] > 0)

        {

            return dp[l][r];
        }

        if (nums.size() < 2)

        {

            return 0;
        }

        if (nums.size() == 2)

        {

            return dp[l][r] = (nums[l] + nums[r] == tar);
        }

        else

        {

            if (nums[l] + nums[r] == tar)

            {

                dp[l][r] = max(dp[l][r], solve(l + 1, r - 1, nums, tar) + 1);
            }

            if (nums[l] + nums[l + 1] == tar)

            {

                dp[l][r] = max(dp[l][r], solve(l + 2, r, nums, tar) + 1);
            }

            if (nums[r] + nums[r - 1] == tar)

            {

                dp[l][r] = max(dp[l][r], solve(l, r - 2, nums, tar) + 1);
            }

            return dp[l][r];
        }
    }

    int maxOperations(vector<int> &nums)
    {

        dp = new int[2001][2001];
        memset(dp, sizeof(dp), 0);
        int ans = 0;
        ans = solve(0, nums.size() - 1, nums, nums.front() + nums.back());
        memset(dp, sizeof(dp), 0);
        ans = max(solve(0, nums.size() - 1, nums, nums.front() + *(nums.begin() + 1)), ans);
        memset(dp, sizeof(dp), 0);
        ans = max(solve(0, nums.size() - 1, nums, *nums.rbegin() + *(nums.rbegin() +1)), ans);
        return ans;
    }
};

int main(void)

{

    vector<int> arr{3, 2, 1, 2, 3, 4};

    Solution s;

    s.maxOperations(arr);
}

// @lc code=end

/*

// @lcpr case=start

// [3,2,1,2,3,4]\n

// @lcpr case=end



// @lcpr case=start

// [3,2,6,1,4]\n

// @lcpr case=end



 */
