/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30204
 *
 * [496] 下一个更大元素 I
 *
 * https://leetcode.cn/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (72.18%)
 * Likes:    1207
 * Dislikes: 0
 * Total Accepted:    341.6K
 * Total Submissions: 473.1K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
 *
 * 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
 *
 * 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定
 * nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
 *
 * 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
 * 输出：[-1,3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 * - 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
 * - 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
 *
 * 示例 2：
 *
 * 输入：nums1 = [2,4], nums2 = [1,2,3,4].
 * 输出：[3,-1]
 * 解释：nums1 中每个值的下一个更大元素如下所述：
 * - 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
 * - 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * nums1和nums2中所有整数 互不相同
 * nums1 中的所有整数同样出现在 nums2 中
 *
 *
 *
 *
 * 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> aux;
        int l = 0, r = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(m);
        while (r < m)
        {
            if (aux.empty())
            {
                aux.push(r++);
            }
            else if (nums2[aux.top()] < nums2[r])
            {
                ans[aux.top()] = nums2[r];
                aux.pop();
            }
            else
            {
                aux.push(r++);
            }
        }
        while (!aux.empty())
        {
            ans[aux.top()] = -1;
            aux.pop();
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[nums2[i]] = ans[i];
        }
        vector<int> res;
        for (int var : nums1)
        {
            res.push_back(mp[var]);
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 2, 4};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    sol.nextGreaterElement(nums1, nums2);
    return 0;
}
/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */