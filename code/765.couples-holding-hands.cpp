/*
 * @lc app=leetcode.cn id=765 lang=cpp
 * @lcpr version=30204
 *
 * [765] 情侣牵手
 *
 * https://leetcode.cn/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (67.21%)
 * Likes:    562
 * Dislikes: 0
 * Total Accepted:    56K
 * Total Submissions: 83.3K
 * Testcase Example:  '[0,2,1,3]'
 *
 * n 对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手。
 *
 * 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的 ID。情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2,
 * 3)，以此类推，最后一对是 (2n-2, 2n-1)。
 *
 * 返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起。 每次交换可选择任意两人，让他们站起来交换座位。
 *
 *
 *
 * 示例 1:
 *
 * 输入: row = [0,2,1,3]
 * 输出: 1
 * 解释: 只需要交换row[1]和row[2]的位置即可。
 *
 *
 * 示例 2:
 *
 * 输入: row = [3,2,0,1]
 * 输出: 0
 * 解释: 无需交换座位，所有的情侣都已经可以手牵手了。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 2n == row.length
 * 2 <= n <= 30
 * n 是偶数
 * 0 <= row[i] < 2n
 * row 中所有元素均无重复
 *
 *
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
#define LOCAL
#ifdef LOCAL
#endif
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int ans = 0;
        int n = row.size();
        for (int i = 0; i < n; i+=2)
        {
            if (row[i + 1]/2 == row[i]/2)
            {
                continue;
            }
            for(int j = i+1;j<n;j++)
            {
                if(row[i]/2 == row[j]/2)
                {
                    swap(row[j], row[i+1]);
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    vector<int> row = {6,2,1,7,4,5,3,8,0,9};
    int ans = s.minSwapsCouples(row);
    cout << ans << endl;
    return 0;
}
/*
// @lcpr case=start
// [0,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,0,1]\n
// @lcpr case=end

 */
