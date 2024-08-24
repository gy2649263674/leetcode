/*
 * @lc app=leetcode.cn id=3137 lang=cpp
 * @lcpr version=30204
 *
 * [3137] K 鍛ㄦ湡瀛楃涓查渶瑕佺殑鏈€灏戞搷浣滄鏁?
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
#include <string.h>
#include<map>
//#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
	int minimumOperationsToMakeKPeriodic(string word, int k)
	{
		/*int ans = 1e9;
		int len = word.length();
		for (int i = 0; i +k <= word.length(); i++)
		{
			if (i%k == 0)
			{
				string ss = word.substr(i, k);
				int tmp =0;
				for (int j = 0; j+k <= len; j += k)
				{
					if (word.substr(j, k) !=ss)
					{
						++tmp;
					}
				}
				ans = min(ans,tmp);
			}
		}
		return ans;*/
		map<string, int>mp;
		int len = word.length();
		for (int i = 0; i < len; i+=k)
		{
			mp[word.substr(i, k)]++;
		}
		int N = len / k;
 		int ans = 1e9;
		for (auto &[_,times] : mp)
		{
			ans = min(ans, N - times);
		}
		return ans;
	}
};

//int main(void)
//{
//	Solution s;
//	cout << s.minimumOperationsToMakeKPeriodic("aagnnannnnnnnnn", 1);
//	return 0;
//
//}