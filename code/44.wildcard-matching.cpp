///*
// * @lc app=leetcode.cn id=44 lang=cpp
// * @lcpr version=30204
// *
// * [44] 通配符匹配
// *
// * https://leetcode.cn/problems/wildcard-matching/description/
// *
// * algorithms
// * Hard (34.10%)
// * Likes:    1162
// * Dislikes: 0
// * Total Accepted:    161.8K
// * Total Submissions: 474.7K
// * Testcase Example:  '"aa"\n"a"'
// *
// * 给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
// *
// *
// * '?' 可以匹配任何单个字符。
// * '*' 可以匹配任意字符序列（包括空字符序列）。
// *
// *
// *
// *
// * 判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。
// *
// *
// *
// *
// * 示例 1：
// *
// * 输入：s = "aa", p = "a"
// * 输出：false
// * 解释："a" 无法匹配 "aa" 整个字符串。
// *
// *
// * 示例 2：
// *
// * 输入：s = "aa", p = "*"
// * 输出：true
// * 解释：'*' 可以匹配任意字符串。
// *
// *
// * 示例 3：
// *
// * 输入：s = "cb", p = "?a"
// * 输出：false
// * 解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// *
// *
// *
// *
// * 提示：
// *
// *
// * 0 <= s.length, p.length <= 2000
// * s 仅由小写英文字母组成
// * p 仅由小写英文字母、'?' 或 '*' 组成
// *
// *
// */
//
//// int dfs(int l, int sh)
//// {
//// 	if (l < 0)
//// 	{
//// 		while (sh >= 0)
//// 		{
//// 			if (p[sh] != '*')
//// 			{
//// 				return 2;
//// 			}
//// 			--sh;
//// 		}
//// 		return 1;
//// 	}
//// 	if (sh < 0 && l >= 0)
//// 	{
//// 		return 2;
//// 	}
//// 	if (dp[l][sh] == 2)
//// 	{
//// 		return 2;
//// 	}
//// 	if (p[sh] == '*')
//// 	{
//// 		bool ans = false;
//// 		for (int i = 0; i <= l + 1; i++)
//// 		{
//// 			ans = dfs(l - i, sh - 1) == 1 ? 1 : 0;
//// 			if (ans == 1)
//// 			{
//// 				break;
//// 			}
//// 		}
//// 		return dp[l][sh] = ans ? 1 : 2;
//// 	}
//// 	else if (p[sh] == '?')
//// 	{
//// 		return dp[l][sh] = dfs(l - 1, sh - 1) == 1 ? 1 : 2;
//// 	}
//// 	else
//// 	{
//// 		return dp[l][sh] = s[l] == p[sh] && dfs(l - 1, sh - 1) == 1 ? 1 : 2;
//// 	}
//// };
//
//// bool isMatch(string s, string p)
//// {
//// 	// int dp[2001][2001] = {false};
//// 	dp = vector<vector<int>>(2000, vector<int>(2000, 0));
//
//// 	auto dp2 = vector<vector<int>>(2000, vector<int>(2000, 0));
//// 	dp[0][0] = 0;
//// 	dp2[0][0] = 1;
//// 	dp2[0][1] = p[0] == '*';
//
//// 	//for (int i = 1; i <= p.length(); i++)
//// 	//{
//// 	//	if (p[i-1] == '*')
//// 	//	{
//// 	//		dp2[0][i] = 1;
//// 	//		//dp[0][j] = 1;
//// 	//	}
//// 	//}
//// 	for (int i = 1; i <= s.length(); i++)
//// 	{
//// 		//auto able = vector < bool >(i, 0);
//// 		for (int j = 1; j <= p.length(); j++)
//// 		{
//
//// 			if (p[j - 1] == '*')
//// 			{
//// 				bool flag = false;
//// 				// i in s j in p len can be matched
//// 				for (int l = i; l >= 0; l--)
//// 				{
//// 					if (dp2[l][j - 1])
//// 					{
//// 						//0-j-1 can be used
//// 						dp2[i][j] = true;
//// 						flag = true;
//// 						break;
//// 					}
//// 				}
//// 				if (!flag)
//// 				{
//// 					dp2[i][j] = false;
//// 					//dp[i][j] = dp[i][j - 1];
//// 					break;
//// 				}
//// 			}
//// 			else
//// 			{
//// 				//dp[i][j] = dp[i-1][j - 1] + (s[i - 1] == p[j - 1]);
//// 				dp2[i][j] = (s[i - 1] == p[j - 1]||p[j-1] == '?') && (dp2[i - 1][j - 1]);
//// 			}
//// 		}
//// 	}
//// 	return dp[s.length()][p.length()] == s.length();
//// 	// return dfs(s.length() - 1, p.length() - 1) == 1;
//// }
//// }
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
//	bool isMatch(string s, string p)
//	{
//		vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, 0));
//		dp[0][0] = 1;
//		// for (int j = 1; j <=p.length() && p[j - 1] == '*'; j++)
//		// 	for (int i = 0; i <= s.length(); i++)
//		// 	{
//		// 		dp[i][j] = 1;
//		// 	}
//		for (int j = 1; j<=p.length()&&p[j-1] == '*'; j++)
//		{
//			dp[0][j] = 1;
//		}
//		// actually only the first state need to be ensured 
//		for (int i = 1; i <= s.length(); i++)
//		{
//			for (int j = 1; j <= p.length(); j++)
//			{
//				if (p[j - 1] == '*')
//				{
//					dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1];
//					// match a s or match non
//				}
//				else if (p[j - 1] == '?')
//				{
//					dp[i][j] = dp[i - 1][j - 1];
//				}
//				else
//				{
//					dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
//				}
//			}
//		}
//		return dp.back().back();
//	}
//};
//// @lc code=end
//int main(void)
//{
//	Solution s;
//	//
//	cout << s.isMatch("abced", "*a*b") << endl;
//	return 0;
//}
///*
//// @lcpr case=start
//// "adceb"\n"*a*b"\n
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
//// @lcpr case=start
//// "acdcb"\n"a*c?b"\n
//// @lcpr case=end
//
// */