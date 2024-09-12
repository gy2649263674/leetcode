///*
// * @lc app=leetcode.cn id=2555 lang=cpp
// * @lcpr version=30204
// *
// * [2555] 两个线段获得的最多奖品
// *
// * https://leetcode.cn/problems/maximize-win-from-two-segments/description/
// *
// * algorithms
// * Medium (41.80%)
// * Likes:    53
// * Dislikes: 0
// * Total Accepted:    4.2K
// * Total Submissions: 9.9K
// * Testcase Example:  '[1,1,2,2,3,3,5]\n2'
// *
// * 在 X轴 上有一些奖品。给你一个整数数组 prizePositions ，它按照 非递减 顺序排列，其中 prizePositions[i] 是第 i
// * 件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数 k 。
// *
// * 你可以选择两个端点为整数的线段。每个线段的长度都必须是 k
// * 。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。
// *
// *
// * 比方说 k = 2 ，你可以选择线段 [1, 3] 和 [2, 4] ，你可以获得满足 1 <= prizePositions[i] <= 3 或者 2
// * <= prizePositions[i] <= 4 的所有奖品 i 。
// *
// *
// * 请你返回在选择两个最优线段的前提下，可以获得的 最多 奖品数目。
// *
// *
// *
// * 示例 1：
// *
// * 输入：prizePositions = [1,1,2,2,3,3,5], k = 2
// * 输出：7
// * 解释：这个例子中，你可以选择线段 [1, 3] 和 [3, 5] ，获得 7 个奖品。
// *
// *
// * 示例 2：
// *
// * 输入：prizePositions = [1,2,3,4], k = 0
// * 输出：2
// * 解释：这个例子中，一个选择是选择线段 [3, 3] 和 [4, 4] ，获得 2 个奖品。
// *
// *
// *
// *
// * 提示：
// *
// *
// * 1 <= prizePositions.length <= 10^5
// * 1 <= prizePositions[i] <= 10^9
// * 0 <= k <= 10^9
// * prizePositions 有序非递减。
// *
// *
// */
//// this will jump the part between cur and cur + k
//// i = next-1;
//// while (i + 1 < pos.size() && pos[i] == pos[i + 1])
////{
////    i++;
//// }
///*if (i != j)
//{
//    cout<<i<<" "<<j<< endl;
//    system("pause");
//}*/
//
//// if (nnext == pos.end())
//// {
////     next = pos.size();
//// }
//// else
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
//class Solution
//{
//public:
//#define pii pair<int, int>
//    class cmp
//    {
//    public:
//        bool operator()(const pii &a, const pii &b)
//        {
//            return a.second < b.second;
//        }
//    };
//    int maximizeWin(vector<int> &pos, int k)
//    {
//        int n = pos.size();
//        vector<int> dp(n + 1);
//        int ans = 0;
//        for (int i = 0, l = 0; i < n; ++i)
//        {
//            while (pos[i] - pos[l] > k)
//            {
//                ++l;
//            }
//            ans = max(ans, i - l + 1 + dp[l]);
//            dp[i + 1] = max(dp[i], i - l + 1);
//        }
//        return ans;
//    }
//    int maximizeWin1(vector<int> &pos, int k)
//    {
//        // enum the right seg
//        int n = pos.size();
//        vector<int> dp(n + 1);
//        int ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            int l = lower_bound(pos.begin(), pos.end(), pos[i] - k) - pos.begin();
//            ans = max(ans, i - l + 1 + dp[l]);
//            dp[i + 1] = max(dp[i], i - l + 1);
//        }
//        // dp[l] is the max end with a num before i
//        return ans;
//    }
//    /*
//// @lcpr case=start
//// [1,1,2,2,3,3,5]\n2\n
//// @lcpr case=end
//
//// @lcpr case=start
//// [1,2,3,4]\n0\n
//// @lcpr case=end
//
// */
//
//    int maximizeWin2(vector<int> &pos, int k)
//    {
//        // ---
//        // ---
//        // max can reach when at the ith pos
//        int n = pos.size();
//        int pre = 0;
//        vector<pii> val;
//        priority_queue<pii, deque<pii>, cmp> aux;
//        for (int i = 0; i < n; i++)
//        {
//            int j = i;
//            int cur = pos[i];
//            auto next = upper_bound(pos.begin(), pos.end(), cur + k) - pos.begin();
//
//            aux.push({cur, next - i});
//            val.push_back({cur, next - i});
//            i = upper_bound(pos.begin(), pos.end(), cur) - pos.begin() - 1;
//        }
//        int ans = 0;
//        for (int i = 0; i < val.size(); i++)
//        {
//            while (!aux.empty() && (aux.top().first <= val[i].first + k))
//            {
//                aux.pop();
//            }
//            ans = max(ans, val[i].second + (aux.empty() ? 0 : aux.top().second));
//        }
//        return ans;
//    }
//};
//// @lc code=end
//
//int main(void)
//{
//    Solution s;
//    cout << s.maximizeWin({3937, 3938, 3939, 3951, 3951, 3959, 3975, 3988, 3993, 4010, 4031, 4033, 4036, 4038, 4039, 4041, 4047, 4058, 4059, 4064, 4072, 4081, 4084, 4084, 4089, 4094, 4098, 4112, 4114, 4116, 4123, 4123, 4127, 4130, 4135, 4143, 4149, 4152, 4163, 4164, 4176, 4178, 4180, 4198, 4216, 4224, 4233, 4240, 4253, 4259, 4273, 4286, 4305, 4322, 4335, 4350, 4364, 4378, 4396, 4397, 4398, 4404, 4415, 4421, 4430, 4469, 4476, 4490, 4492, 4497, 4504, 4519, 4519, 4525, 4526, 4530, 4530, 4540, 4550, 4554, 4563, 4571, 4571, 4595, 4595, 4606, 4639, 4639, 4660, 4663, 4676, 4678, 4680, 4695, 4697, 4709, 4709, 4711, 4724, 4751, 4781, 4786, 4786, 4794, 4797, 4801, 4807, 4808, 4817, 4822, 4824, 4825, 4840, 4851, 4887, 4889, 4891, 4910, 4917, 4927, 4931, 4932, 4951, 4959, 4964, 4993, 4997, 5003, 5003, 5006, 5006, 5022, 5029, 5035, 5043, 5045, 5045, 5046, 5059, 5060, 5079, 5084, 5105, 5109, 5109, 5112, 5120, 5126, 5130, 5142, 5143, 5151, 5152, 5154, 5156, 5168, 5189, 5213, 5214, 5223, 5226, 5235, 5247, 5259, 5272, 5289, 5303, 5309, 5317, 5322, 5344, 5347, 5352, 5374, 5379, 5380, 5383, 5385, 5391, 5418, 5425, 5429, 5432, 5479, 5486, 5490, 5502, 5502, 5505, 5506, 5509, 5515, 5518, 5519, 5521, 5526, 5528, 5533, 5536, 5536, 5538, 5555, 5556, 5557, 5557, 5566, 5571, 5580, 5585, 5596, 5604, 5619, 5634, 5649, 5668, 5694, 5696, 5699, 5701, 5704, 5709, 5732, 5745, 5745, 5746, 5749, 5762, 5766, 5766, 5770, 5773, 5796, 5810, 5817, 5823, 5838, 5843, 5846, 5860, 5869, 5872, 5877, 5880, 5896, 5899, 5902, 5905, 5910, 5913, 5913, 5915, 5923}, 220);
//    return 0;
//}
