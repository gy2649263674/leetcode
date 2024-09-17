/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 * @lcpr version=30204
 *
 * [2848] 与车相交的点
 *
 * https://leetcode.cn/problems/points-that-intersect-with-cars/description/
 *
 * algorithms
 * Easy (73.58%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 16.2K
 * Testcase Example:  '[[3,6],[1,5],[4,7]]'
 *
 * 给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。对于任意下标 i，nums[i] = [starti, endi] ，其中
 * starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。
 *
 * 返回数轴上被车 任意部分 覆盖的整数点的数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [[3,6],[1,5],[4,7]]
 * 输出：7
 * 解释：从 1 到 7 的所有点都至少与一辆车相交，因此答案为 7 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [[1,3],[5,8]]
 * 输出：7
 * 解释：1、2、3、5、6、7、8 共计 7 个点满足至少与一辆车相交，因此答案为 7 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * nums[i].length == 2
 * 1 <= starti <= endi <= 100
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

    int numberOfPoints(vector<vector<int>> &nums)
    {
        // only to remembe whether has difit currently
        int diff[201] = {0};
        for(auto &var:nums)
        {
            ++diff[var[0]];
            --diff[var[1]+1];
        }
        int ans = 0 ,cur = 0;
        for(int i = 0;i<101;i++)
        {
            cur+= diff[i];
            ans+= cur>0?1:0;
        }
        return ans;
    }
    /*
// @lcpr case=start
// [[3,6],[1,5],[4,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,8]]\n
// @lcpr case=end

 */
    int numberOfPoints2(vector<vector<int>> &nums)
    {
        deque<pair<int, int>> aux;
        sort(nums.begin(), nums.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        for (auto var : nums)
        {
            if (aux.empty())
            {
                aux.push_back({var[0], var[1]});
            }
            else
            {
                if (aux.back().second >= var[0])
                {
                    pair<int,int>tmp ={aux.back().first,max(var[1],aux.back().second)};
                    aux.pop_back();
                    aux.push_back(tmp);
                }
                else
                {
                    aux.push_back({var[0],var[1]});
                }
            }
        }
        int ans = 0;
        for(auto var:aux)
        {
            ans+=var.second-var.first+1;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[3,6],[1,5],[4,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,8]]\n
// @lcpr case=end

 */
