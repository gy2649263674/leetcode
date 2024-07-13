/*
 * @lc app=leetcode.cn id=781 lang=cpp
 * @lcpr version=30203
 *
 * [781] 森林中的兔子
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
    int numRabbits(vector<int>& an) {
        vector<int>arr(1001,0);
        for(int i = 0;i<an.size();i++)
        {
            ++arr[an[i]];
        }
        int ans = 0;
        for(int i = 0;i<1001;i++)
        {
            ans+=(arr[i]-1)/(i+1)*(i+1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [10,10,10]\n
// @lcpr case=end

 */

