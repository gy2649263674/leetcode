/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    vector<string> letterCombinations(string digits)
    {
        if(digits.length() == 0)
        {
            return {};
        }
        string st[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        char tmp[10] = {0};
        char*o = tmp;
        function<void(int,char*)> dfs = [&](int dep,char*p) 
        {
            if(dep == digits.size())
            {
                ans.push_back(string(tmp));
                return ;
            }
            for(int i = 0;i<st[digits[dep]-'0'].length();i++)
            {
                *p++ = st[digits[dep]-'0'][i];
                dfs(dep+1,p);
                *p-- = 0;
            }
        };
        dfs(0,o);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
