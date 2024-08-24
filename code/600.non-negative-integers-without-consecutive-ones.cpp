/*
 * @lc app=leetcode.cn id=600 lang=cpp
 * @lcpr version=30204
 *
 * [600] 不含连续1的非负整数
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
    int show(int n)
    {
        int cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            bitset<32> tmp = i;
            int j = 0;
            for (; j < 31; j++)
            {
                if (tmp[j] == tmp[j + 1] && tmp[j] == 1)
                {
                    break;
                }
            }
            if (j == 31)
            {
                ++cnt;
            }
        }
        return cnt;
    }
    int findIntegers(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " " <<bitset<32>(i) << endl;
        }
        return 0;
    }
};
int main(void)
{
    Solution ss;
    ss.findIntegers(1000);
    return 0;
}
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
