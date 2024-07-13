/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 * @lcpr version=30203
 *
 * [2288] 价格减免
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
//#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
typedef long long ll;
#define double long double 
#define double long double 
typedef long long ll;
class Solution
{
public:
	string discountPrices(string& s, int d)
	{
		deque<pair<int, string>> pos;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '$'&&(i == 0 ||s[i-1] == ' '))
			{
				string tmp;
				bool is = true;
				int j = i + 1;
				for (; j < s.length() && s[j] != ' '; j++)
				{
					if (!isdigit(s[j]))
					{
						is = false;
						break;
					}
					else
					{
						tmp += s[j];
					}
				}
				if (is&&tmp!= "")
				{
					//reverse(tmp.begin(), tmp.end());
					 double ans = atol(&tmp[0]);
					ans =ans*( (100.0l-d) / 100.0l);
					stringstream ss;
					string tmp;
					ss << setiosflags(ios::fixed) << setprecision(2) << ans;
					ss >> tmp;
					pos.push_back({ i, tmp });
				}
				i = j - 1;
			}
		}
		if (pos.empty())
		{
			return s;
		}
		int pre = 0;
		string re;
		pos.push_back({ s.length()-1, "" });
		for (int i = 0; i < pos.size(); i++)
		{
			int j = pre;
			for (; j <= pos[i].first; j++)
			{
				re.push_back(s[j]);
			}
			re += pos[i].second;
			pre = j;
			while (pre < s.length() && s[pre] != ' ')
			{
				++pre;
			}
		}
		return re;
	}
};
// class Solution
// {
// public:
// 	string discountPrices(string& s, int d)
// 	{
// 		deque<pair<int, string>> pos;
// 		for (int i = 0; i < s.length(); i++)
// 		{
// 			if (s[i] == '$')
// 			{
// 				string tmp;
// 				bool is = true;
// 				int j = i + 1;
// 				for (; j < s.length() && s[j] != ' '; j++)
// 				{
// 					if (!isdigit(s[j]))
// 					{
// 						is = false;
// 						break;
// 					}
// 					else
// 					{
// 						tmp += s[j];
// 					}
// 				}
// 				if (is&&tmp!= "")
// 				{
// 					//reverse(tmp.begin(), tmp.end());
// 					double ans = atol(&tmp[0]);
// 					ans =ans*( (100.0l-d) / 100.0l);
// 					stringstream ss;
// 					string tmp;
// 					ss << setiosflags(ios::fixed) << setprecision(2) << ans;
// 					ss >> tmp;
// 					pos.push_back({ i, tmp });
// 				}
// 				i = j - 1;
// 			}
// 		}
// 		if (pos.empty())
// 		{
// 			return s;
// 		}
// 		int pre = 0;
// 		string re;
// 		pos.push_back({ s.length()-1, "" });
// 		for (int i = 0; i < pos.size(); i++)
// 		{
// 			int j = pre;
// 			for (; j <= pos[i].first; j++)
// 			{
// 				re.push_back(s[j]);
// 			}
// 			re += pos[i].second;
// 			pre = j;
// 			while (pre < s.length() && s[pre] != ' ')
// 			{
// 				++pre;
// 			}
// 		}
// 		return re;
// 	}
// };
// @lc code=end

/*
// @lcpr case=start
// "there are $1 $2 and 5$ candies in the shop"\n50\n
// @lcpr case=end

// @lcpr case=start
// "1 2 $3 4 $5 $6 7 8$ $9 $10$"\n100\n
// @lcpr case=end

 */
