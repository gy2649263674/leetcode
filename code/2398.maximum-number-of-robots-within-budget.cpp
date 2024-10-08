///*
//*
//	int maximumRobots2(vector<int> times, vector<int> costs, long long budget)
//	{
//		int n = times.size();
//		long long l = 0, r = n, ans = 0;
//		vector<long long> pre(n + 1, 0);
//		for (int i = 1; i <= n; i++)
//		{
//			pre[i] = pre[i - 1] + costs[i - 1];
//		}
//		{
//			long long cost = 0;
//			function<bool(long long)> check = [&](long long cur) -> bool { //*max_element(times.begin() + i, times.begin() + i + cur)
//				if (cur == 0)
//				{
//					return true;
//				}
//				deque<pair<int, int>> aux;
//				for (int i = 0; i < cur - 1; i++)
//				{
//					while (!aux.empty() && (aux.back().second < times[i]))
//					{
//						aux.pop_back();
//					}
//					aux.push_back({ i, times[i] });
//				}
//				for (int i = 0; i + cur <= n; i++)
//				{
//					while (!aux.empty() && (aux.back().second < times[i + cur - 1]))
//					{
//						aux.pop_back();
//					}
//					while (!aux.empty() && aux.front().first < i)
//					{
//						aux.pop_front();
//					}
//					aux.push_back({ i + cur - 1, times[i + cur - 1] });
//					cost = cur * (pre[i + cur] - pre[i]) + aux.front().second;
//					if (cost <= budget)
//					{
//						return true;
//					}
//				}
//				return false;
//				};
//
//			while (l <= r)
//			{
//				long long m = (l + r) >> 1;
//				if (check(m))
//				{
//					ans = max(ans, m);
//					l = m + 1;
//				}
//				else
//				{
//					r = m - 1;
//				}
//			}
//		}
//		return ans;
//	}
// * @lc app=leetcode.cn id=2398 lang=cpp
// * @lcpr version=30204
// *
// * [2398] 预算内的最多机器人数目
// *
// * https://leetcode.cn/problems/maximum-number-of-robots-within-budget/description/
// *
// * algorithms
// * Hard (37.39%)
// * Likes:    41
// * Dislikes: 0
// * Total Accepted:    7.4K
// * Total Submissions: 18.5K
// * Testcase Example:  '[3,6,1,3,4]\n[2,1,3,4,5]\n25'
// *
// * 你有 n 个机器人，给你两个下标从 0 开始的整数数组 chargeTimes 和 runningCosts ，两者长度都为 n 。第 i
// * 个机器人充电时间为 chargeTimes[i] 单位时间，花费 runningCosts[i] 单位时间运行。再给你一个整数 budget 。
// *
// * 运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，其中
// * max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。
// *
// * 请你返回在 不超过 budget 的前提下，你 最多 可以 连续 运行的机器人数目为多少。
// *
// *
// *
// * 示例 1：
// *
// * 输入：chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
// * 输出：3
// * 解释：
// * 可以在 budget 以内运行所有单个机器人或者连续运行 2 个机器人。
// * 选择前 3 个机器人，可以得到答案最大值 3 。总开销是 max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24
// * ，小于 25 。
// * 可以看出无法在 budget 以内连续运行超过 3 个机器人，所以我们返回 3 。
// *
// *
// * 示例 2：
// *
// * 输入：chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
// * 输出：0
// * 解释：即使运行任何一个单个机器人，还是会超出 budget，所以我们返回 0 。
// *
// *
// *
// *
// * 提示：
// *
// *
// * chargeTimes.length == runningCosts.length == n
// * 1 <= n <= 5 * 10^4
// * 1 <= chargeTimes[i], runningCosts[i] <= 10^5
// * 1 <= budget <= 10^15
// *
// *
// */
//
//// @lcpr-template-start
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
//// @lcpr-template-end
//// @lc code=start
//#define pii pair<int, int>
//class Solution
//{
//public:
//	int maximumRobots(vector<int> times, vector<int> costs, long long budget)
//	{
//		int l = 0, r = 0;
//		int n = costs.size();
//		deque<pii> aux;
//		int ans = 0;
//		long long sum = 0;
//		while (r < n)
//		{
//			while (!aux.empty() && aux.back().second < times[r])
//			{
//				aux.pop_back();
//			}
//			while (!aux.empty() && aux.front().first < l&&aux.front().second + (r - l) * sum>budget)
//			{
//				aux.pop_front();
//				sum-=cso[]
//			}
//			aux.push_back({r, times[r]});
//			sum += costs[r];
//			// if (cur > budget)
//			// long long cur = 
//			// {
//				// sum -= costs[l];
//			else
//			{
//				ans = max(ans, r - l);
//				++r;
//			}
//		}
//		return ans;
//	}
//	// @lcpr case=start
//	// [3,6,1,3,4]\n[2,1,3,4,5]\n25\n
//	// @lcpr case=end
//
//	// @lcpr case=start
//	// [11,12,19]\n[10,8,7]\n19\n
//	// @lcpr case=end
//
//	// @lcpr case=start
//	// [74,46,19,34,7,87,7,40,28,81,53,39,3,46,21,40,76,44,88,93,44,50,22,59,46,60,36,24,50,40,56,5,39,9,24,74,7,14,95,45,36,17,22,12,53,41,2,33,100,73,20,70,81,91,28,98,47,88,79,100,78,38,44,74,48,76,73,92,28,30,95,87]\n[11,33,15,40,8,28,97,89,51,42,17,57,45,5,63,53,23,43,76,64,86,86,89,53,94,91,78,12,90,29,79,48,35,6,88,79,82,76,44,93,83,55,65,96,86,24,54,65,94,4,26,73,51,85,47,99,17,14,76,2,39,52,58,5,15,35,79,16,94,16,59,50]\n447
//	// @lcpr case=end
//};
//// @lc code=end
//int main(void)
//{
//	Solution s;
//	cout << s.maximumRobots({3, 6, 1, 3, 4},
//							{2, 1, 3, 4, 5},
//							25);
//}
///*
//// @lcpr case=start
//// [3,6,1,3,4]\n[2,1,3,4,5]\n25\n
//// @lcpr case=end
//
//// @lcpr case=start
//// [11,12,19]\n[10,8,7]\n19\n
//// @lcpr case=end
//
//// @lcpr case=start
//[74,46,19,34,7,87,7,40,28,81,53,39,3,46,21,40,76,44,88,93,44,50,22,59,46,60,36,24,50,40,56,5,39,9,24,74,7,14,95,45,36,17,22,12,53,41,2,33,100,73,20,70,81,91,28,98,47,88,79,100,78,38,44,74,48,76,73,92,28,30,95,87]\n[11,33,15,40,8,28,97,89,51,42,17,57,45,5,63,53,23,43,76,64,86,86,89,53,94,91,78,12,90,29,79,48,35,6,88,79,82,76,44,93,83,55,65,96,86,24,54,65,94,4,26,73,51,85,47,99,17,14,76,2,39,52,58,5,15,35,79,16,94,16,59,50]\n447
//// @lcpr case=end
//
////@lcpr case=start
////[74,46,19,34,7,87,7,40,28,81,53,39,3,46,21,40,76,44,88,93,44,50,22,59,46,60,36,24,50,40,56,5,39,9,24,74,7,14,95,45,36,17,22,12,53,41,2,33,100,73,20,70,81,91,28,98,47,88,79,100,78,38,44,74,48,76,73,92,28,30,95,87]\n[11,33,15,40,8,28,97,89,51,42,17,57,45,5,63,53,23,43,76,64,86,86,89,53,94,91,78,12,90,29,79,48,35,6,88,79,82,76,44,93,83,55,65,96,86,24,54,65,94,4,26,73,51,85,47,99,17,14,76,2,39,52,58,5,15,35,79,16,94,16,59,50]\n447
////@lcpe case=end
// */
