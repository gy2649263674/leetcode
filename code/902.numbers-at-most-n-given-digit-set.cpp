/*
 * @lc app=leetcode.cn id=902 lang=cpp
 * @lcpr version=30204
 *
 * [902] 鏈€澶т负 N 鐨勬暟瀛楃粍鍚?
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
#include <utility>·
#include <vector>
#include <string>
#include <bits/stdc++.h>
//#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
	vector<int> arr;
	int solve(int cur, int l)
	{
		int tl = to_string(cur).length();
		if (l<0)
		{
			return 0;
		}
		int h = tl<l?0:to_string(cur)[0] - '0';
		auto it = lower_bound(arr.begin(), arr.end(), h);
		if (it == arr.end())
		{
			return pow(arr.size(), l);
		}
		else
		{
			if (*it > h)
			{
				return (it - arr.begin()) * pow(arr.size(), l - 1);
			}
			else
			{
				// eq
				return l == 1? it - arr.begin()+1:solve(cur - pow(10, l - 1) * h,l-1) + (it - arr.begin()) * pow(arr.size(),l-1);
			}
		}
	}
	int atMostNGivenDigitSet(vector<string>& digits, int n)
	{
		int l = to_string(n).length();
		int s1 = 0;
		for (int i = 1; i < digits.size(); i++)
		{
			if (digits[s1] != digits[i])
			{
				s1++;
				digits[s1] = digits[i];
				// arr.push_back(atoi(&digits[s1][0]));
			}
		}
		for (auto var : digits)
		{
			arr.push_back(atoi(&var[0]));
		}
		int ans = 0;
		int s = arr.size();
		// 0 ->  l-1
		for (int i = 1; i < l; i++)
		{
			ans += pow(s, i);
		}
		ans += solve(n,l);
		// l bit
		int tmp = 1;
		return ans;
	}
};
// @lc code=end

/*
// @lcpr case=start
// ["1","3","5","7"]\n100\n
// @lcpr case=end

// @lcpr case=start
// ["1","4","9"]\n1000000000\n
// @lcpr case=end

// @lcpr case=start
// ["7"]\n8\n
// @lcpr case=end

 */

int main(void)
{
	Solution s;
	cout << s.atMostNGivenDigitSet({ "1","5","7","8" }, 10212);
	return 0;
}