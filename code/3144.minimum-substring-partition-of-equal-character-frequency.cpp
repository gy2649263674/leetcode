///*
// * @lc app=leetcode.cn id=3144 lang=cpp
// * @lcpr version=30204
// *
// * [3144] 分割字符频率相等的最少子字符串
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
//// #include <bits/stdc++.h>
//////  @lcpr-template-end
//////  @lc code=start
////class Solution
////{
////public:
////    int minimumSubstringsInPartition(string s)
////    {
////
////        int dp[1001] = {0};
////        memset(dp, 0x3f3f3f3f, sizeof(dp));
////        dp[0] = 0;
////        for (int i = 1; i <= s.length(); i++)
////        {
////            unordered_map<char, int> tot;
////            int maxn = 0;
////            for (int j = i - 1; j >= 0; j--)
////            {
////                maxn = max(maxn, ++tot[s[j]]);
////                if (tot.size() * maxn == (i - j))
////                    dp[i] = min(dp[j] + 1, dp[i]);
////            }
////        }
////        return dp[s.length()];
////        // ss = s;
////        int pre[1001][26];
////        // memset(pre[0], 0, sizeof(pre));
////        // self and don't include pre
////        // for (int i = 1; i <= s.length(); i++)
////        // {
////        //     for (int j = 0; j < 26; j++)
////        //     {
////        //         pre[i][j] = pre[i - 1][j] + (s[i - 1] == 'a' + j ? 1 : 0);
////        //         // the i st char0
////        //     }
////        // }
////
////        function<bool(int, int)> check = [&](int p, int s) -> bool
////        {
////            if (s - p == 1)
////            {
////                return true;
////            }
////            vector<int> tmp;
////            for (int i = 0; i < 26; i++)
////            {
////                int c = pre[s][i] - pre[p][i];
////                // ignore p self
////                if (!tmp.empty() && c != tmp.back() && c != 0)
////                {
////                    return false;
////                }
////                if (c)
////                {
////                    tmp.push_back(c);
////                }
////            }
////            return true;
////        };
////        function<int(int)> f = [&](int cur) -> int
////        {
////            if (cur == 0)
////            {
////                return 0;
////            }
////            if (cur == 1)
////            {
////                return 1;
////            }
////            if (dp[cur] != 0)
////            {
////                return dp[cur];
////            }
////            int ans = 1e9;
////            int maxele = 0;
////            unordered_map<char, int> maxn;
////            for (int i = cur - 1; i >= 0; i--)
////            {
////                maxele = max(++maxn[s[i]], maxele);
////                if (maxele * maxn.size() == (cur - i))
////                {
////                    ans = min(f(i) + 1, ans);
////                }
////                // i is used
////                // if (check(i, cur))
////                // {
////                //     ans = min(f(i) + 1, ans);
////                // }
////            }
////            return dp[cur] = ans;
////        };
////        return f(s.length());
////    }
////};
////// @lc code=end
////int main(void)
////{
////    Solution s;
////    cout << s.minimumSubstringsInPartition("dasdasdf");
////    return 0;
////}
/////*
////// @lcpr case=start
////// "fabccddg"\n
////// @lcpr case=end
////
////// @lcpr case=start
////// "abababaccddb"\n
////// @lcpr case=end
////
//// */
//
//
////#include <bits/stdc++.h>
////using namespace std;
////class Solution
////{
////public:
////    int maximumLength(vector<int> nums, int k)
////    {
////        if (nums.size() == 0)
////        {
////            return 0;
////        }
////        if (nums.size() == 1)
////        {
////            return 1;
////        }
////        int inf = 1e9;
////        const int N = 1e5;
////        int (*dp)[50] = new int[10000][50]();
////        function<int(int, int, int)> dfs = [&](int i, int k, int suf) -> int
////            {    
////                if (k < 0)
////                {
////                    return -inf;
////                }
////                if (i == 0)
////                {
////                    return nums[0] == suf || k > 0;
////                }
////
////                if (dp[i][k])
////                {
////                    return dp[i][k];
////                }
////                if (nums[i] == suf)
////                {
////                    return dp[i][k] = dfs(i - 1, k, nums[i]) + 1;
////                }
////                else
////                {
////                    return dp[i][k] = max(dfs(i - 1, k - 1, nums[i]) + 1, dfs(i - 1, k, suf));
////                }
////            };
////        int ans = 0;
////        for (int i = nums.size() - 2; i >= 0; i--)
////        {
////            // enum the last element
////            ans = max(ans, dfs(i, k, nums[i + 1]) + 1);
////        }
////        return max(ans, k);
////    }
////};
//////int main(void)
//////{
//////    Solution s;
//////    cout << s.maximumLength({100,94,69,13,31,32,46,39,90,90 }, 0);
//////    return 0;
//////}
//////#include <bits/stdc++.h>
////using namespace std;
////class Solution
////{
////public:
////	int maximumLength(vector<int> nums, int k)
////	{
////		//
////		//int (*dp)[50] = new int[10000][50]{ 0 };
////		//dp[0][0] = 1;
////		//// memset(&dp[0], 1, sizeof(dp[0]));
////		//for (int i = 0; i = k; i++)
////		//{
////		//	dp[0][i] = 1;
////		//}
////		int ans = 1;
////		vector<vector<int>>dp(10000, vector<int>(50, 0));
////		int n = nums.size();
////		for (int i = 0; i < n; i++)
////		{
////			dp[i][0] = 1;
////			// dp[i][j] = max(dp[i][j],dp[x][])
////			// already has j diff in pre i
////			for (int l = 0; l < i; l++)
////			{
////				// transs from l
////				for (int j = 0; j <= min(k, i); j++)
////				{
////					if (j == 0)
////					{
////						dp[i][0] = nums[i] == nums[l] ? dp[l][0] + 1 : dp[i][0];
////					}
////					else
////						dp[i][j] = max(dp[i][j], dp[l][j - (nums[l] != nums[i])] + 1);
////					ans = max(ans, dp[i][j]);
////				}
////			}
////		}
////		return ans;
////	}
////};
////int main(void)
////{
////	Solution s;
////	cout << s.maximumLength({ 30,30,29 }, 0);
////	return 0;
////
//// 
//// 
//// /*
//
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
//#include <vector>
//// @lcpr-template-end
//// @lc code=start
//using namespace std;
//class Solution
//{
//public:
//	bool isMatch(string s, string p)
//	{
//		// int dp[2001][2001] = {false};
//		int n = 0;
//		vector<vector<int>> dp(2000, vector<int>(2000, 0));
//		function<int(int, int)> dfs = [&](int l, int sh) -> int
//			{
//				++n;
//				if (l < 0)
//				{
//					while (sh >= 0)
//					{
//						if (p[sh] != '*')
//						{
//							return 2;
//						}
//						--sh;
//					}
//					return 1;
//				}
//				if (sh < 0 && l >= 0)
//				{
//					return 2;
//				}
//				if (dp[l][sh] == 2)
//				{
//					return 2;
//				}
//				if (p[sh] == '*')
//				{
//					bool ans = false;
//					for (int i = 0; i <= l + 1; i++)
//					{
//						ans = dfs(l - i, sh - 1) == 1 ? 1 : 0;
//						if (ans == 1)
//						{
//							break;
//						}
//					}
//					return dp[l][sh] = ans ? 1 : 2;
//				}
//				else if (p[sh] == '?')
//				{
//					return dp[l][sh] = dfs(l - 1, sh - 1) == 1 ? 1 : 2;
//				}
//				else
//				{
//					return dp[l][sh] = s[l] == p[sh] && dfs(l - 1, sh - 1) == 1 ? 1 : 2;
//				}
//			};
//		int ans = dfs(s.length() - 1, p.length() - 1) == 1;
//		cout << n << endl;
//		return ans;
//	}
//};
//// @lc code=end
//int main(void)
//{
//	Solution s;
//	cout << s.isMatch("cac",
//		"**") << endl;
//	//cout << s.isMatch("aa"
//	//	,"a") << endl;
//	return 0;
//}
///*
//// @lcpr case=start
//// "aa"\n"a"\n
//// @lcpr case=end
//
//// @lcpr case=start
//// "aa"\n"*"\n
//// @lcpr case=end
//
//// @lcpr case=start
//// "cb"\n"?a"\n
//// @lcpr case=end
//
// */
