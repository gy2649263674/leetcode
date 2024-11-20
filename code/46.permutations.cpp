/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        vector<bool> use(n, false);
        vector<int> tmp;
        function<void(int)> dfs = [&](int cur) -> void
        {
            if (cur == n)
            {
                res.push_back(tmp);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (!use[i])
                    {
                        tmp.push_back(nums[i]);
                        use[i] = true;
                        dfs(cur + 1);
                        use[i] = false;
                        tmp.pop_back();
                    }
                }
                return;
            }
        };
        dfs(0);
        return res;
        // for()
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
