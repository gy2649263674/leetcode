/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30204
 *
 * [134] 加油站
 *
 * https://leetcode.cn/problems/gas-station/description/
 *
 * algorithms
 * Medium (47.28%)
 * Likes:    1680
 * Dislikes: 0
 * Total Accepted:    409.5K
 * Total Submissions: 866.9K
 * Testcase Example:  '[1,2,3,4,5]\n[3,4,5,1,2]'
 *
 * 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 *
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
 *
 * 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一
 * 的。
 *
 *
 *
 * 示例 1:
 *
 * 输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * 输出: 3
 * 解释:
 * 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
 * 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
 * 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
 * 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
 * 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
 * 因此，3 可为起始索引。
 *
 * 示例 2:
 *
 * 输入: gas = [2,3,4], cost = [3,4,3]
 * 输出: -1
 * 解释:
 * 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
 * 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
 * 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
 * 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
 * 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
 * 因此，无论怎样，你都不可能绕环路行驶一周。
 *
 *
 *
 * 提示:
 *
 *
 * gas.length == n
 * cost.length == n
 * 1 <= n <= 10^5
 * 0 <= gas[i], cost[i] <= 10^4
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int l = 0, r = 1;
        int cur = gas[l] - cost[l];
        // /{1,2,3,4,5},{3,4,5,1,2}
        bool flag = false;
        while (l < gas.size())
        {
            r%= gas.size();
            if (cur < 0)
            {
                if(l == gas.size()-1&&r!= l)
                {
                    while(r<l&&cur>=0)
                    {
                        cur+= gas[r]-cost[r];
                        ++r;
                    }
                    return cur >=0?l:-1;
                }
                while (cur<0&&l < gas.size())
                {
                    cur += cost[l] - gas[l];
                    ++l;
                }
            }
            else
            {
                flag =  true;
                if (r >= l)
                {
                    while (cur >= 0 && r < gas.size())
                    {
                        cur += -cost[r] + gas[r];
                        r++;
                    }
                    if (cur >= 0)
                    {
                        r = 0;
                        while (r < l&&cur>=0)
                        {
                            cur += -cost[r] + gas[r];
                            r++;
                        }
                        if(r == l)
                        {
                            return cur>=0?l:-1;
                        }
                    }
                    else if(cur<0)
                    {
                        continue;
                    }
                }
                else
                {
                    while (r<l&&cur>=0)
                    {
                        cur+= gas[r]-cost[r];
                        ++r;
                    }
                    if(r == l)
                    {
                        return cur>=0?l:-1;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return r == l&&cur>=0&&flag?l:-1;
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    cout<<s.canCompleteCircuit({1,2,3,4,5},{3,4,5,1,2});
    cout<<s.canCompleteCircuit({5,0,9,4,3,3,9,9,1,2},
{6,7,5,9,5,8,7,1,10,5});
    // cout<<s.canCompleteCircuit({2,3,4},{3,4,3});
    return 0;
}
/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */
