/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=30204
 *
 * [8] 字符串转换整数 (atoi)
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
class Solution// @lc code=start
{
public:
	int myAtoi(string& s)
	{
		int l = 0;
		while (l < s.length() && s[l] == ' ')
		{
			++l;
		}
		bool flag = false;
		if (l<s.length()&&l>= 0 && s[l] == '-')
		{
			flag = true;
			++l;
		}
		else if (l < s.length() && l >= 0 && s[l] == '+')
		{
			flag = false;
			++l;
		}
		long long tmp = 0;
		while (l < s.length() && isdigit(s[l]))
		{
			tmp = tmp * 10 + (s[l] - '0');
			if (tmp > (1ll<<31))
			{
				break;
			}
			++l;
		}
		if (tmp > (1ll << 31))
		{
			if (flag)
			{
				return (-1 << 31);
			}
			else
			{
				return (1ll << 31)-1;
			}
		}
		else
		{
			if (flag)
			{
				return -tmp;
			}
			else
			{
				return (tmp >= -1ll+(1ll << 31)) ? -1 + (1ll << 31) : tmp;
			}
		}
	}

};
// @lc code=endva

// /*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */
