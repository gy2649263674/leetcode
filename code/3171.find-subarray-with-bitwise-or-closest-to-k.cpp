///*
// * @lc app=leetcode.cn id=3171 lang=cpp
// * @lcpr version=30204
// *
// * [3171] 找到按位或最接近 K 的子数组
// *
// * https://leetcode.cn/problems/find-subarray-with-bitwise-or-closest-to-k/description/
// *
// * algorithms
// * Hard (37.10%)
// * Likes:    35
// * Dislikes: 0
// * Total Accepted:    8.7K
// * Total Submissions: 19.9K
// * Testcase Example:  '[1,2,4,5]\n3'
// *
// * 给你一个数组 nums 和一个整数 k 。你需要找到 nums 的一个 子数组 ，满足子数组中所有元素按位或运算 OR 的值与 k 的 绝对差 尽可能
// * 小 。换言之，你需要选择一个子数组 nums[l..r] 满足 |k - (nums[l] OR nums[l + 1] ... OR
// * nums[r])| 最小。
// *
// * 请你返回 最小 的绝对差值。
// *
// * 子数组 是数组中连续的 非空 元素序列。
// *
// *
// *
// * 示例 1：
// *
// *
// * 输入：nums = [1,2,4,5], k = 3
// *
// * 输出：0
// *
// * 解释：
// *
// * 子数组 nums[0..1] 的按位 OR 运算值为 3 ，得到最小差值 |3 - 3| = 0 。
// *
// *
// * 示例 2：
// *
// *
// * 输入：nums = [1,3,1,3], k = 2
// *
// * 输出：1
// *
// * 解释：
// *
// * 子数组 nums[1..1] 的按位 OR 运算值为 3 ，得到最小差值 |3 - 2| = 1 。
// *
// *
// * 示例 3：
// *
// *
// * 输入：nums = [1], k = 10
// *
// * 输出：9
// *
// * 解释：
// *
// * 只有一个子数组，按位 OR 运算值为 1 ，得到最小差值 |10 - 1| = 9 。
// *
// *
// *
// *
// * 提示：
// *
// *
// * 1 <= nums.length <= 10^5
// * 1 <= nums[i] <= 10^9
// * 1 <= k <= 10^9
// *
// *
// */
//
// // @lcpr-template-start
//using namespace std;
//#include <algorithm>
//#include <array>
//#include <bitset>
//#include <climits>
//#include <deque>
//#include <functional>
//#include <iostream>
//#include <list>
//#include <queue>
//#include <stack>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>
//#include <utility>
//#include <vector>
//#include <deque>
//// @lcpr-template-end
//// @lc code=start
//class Solution
//{
//public:
//	int minimumDifference(vector<int> nums, int k)
//	{
//		int l = 0, r = 0, n = nums.size();
//		int cur = nums[0];
//		int ans = abs(cur - k);
//		int st[32] = { 0 };
//		function<int(int, int)> update = [&](int x, int flag) -> int
//			{
//				int res = 0;
//				for (int i = 0; i < 32; i++)
//				{
//					res |= ((st[i] += flag * ((1 << i & x) > 0 ? 1 : 0)) >= 1) ? (1 << i) : 0;
//				}
//				return res;
//			};
//		update(nums[0], 1);
//		while (l < n && r + 1 < n)
//		{
//			// in [l,r] is ored
//			if (cur > k)
//			{
//				if (l == r)
//				{
//					update(nums[l], -1);
//					++r, ++l;
//					cur = update(nums[r], 1);
//				}
//				else
//				{
//					cur = update(nums[l], -1);
//					l++;
//				}
//			}
//			else if (cur < k)
//			{
//				r++;
//				cur = update(nums[r], 1);
//			}
//			else
//			{
//				return 0;
//			}
//			ans = min(ans, abs(k - cur));
//		}
//		while (l + 1 < n)
//		{
//			cur = update(nums[l], -1);
//			l++;
//			ans = min(ans, abs(k - cur));
//
//		}
//		return ans;
//		// i to j
//		//
//		// for()
//	}
//};
//// @lc code=end
//int main(void)
//{
//	Solution s;
//	cout << s.minimumDifference({ 3,58,1,31,21 }, 39);
//	return 0;
//}
///*
//// @lcpr case=start
//// [1,2,4,5]\n3\n
//// @lcpr case=end
//
//// @lcpr case=start
//// [1,3,1,3]\n2\n
//// @lcpr case=end
//
//// @lcpr case=start
//// [1]\n10\n
//// @lcpr case=end
//
// */
